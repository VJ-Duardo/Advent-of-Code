#include <fstream>
#include <string>
#include <vector>

#include "utils/utils.hpp"


namespace utils{

std::string getFileContent(std::string path){
  std::ifstream stream(path);
  std::string content ((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
  return content;
}


std::vector<std::string> getSplitArray(std::string input, std::string delim){
  std::vector<std::string> splitArray;

  size_t pos = 0;
  pos = input.find_first_of(delim);

  while (pos != std::string::npos){
    if (input.substr(0, pos) != "")
      splitArray.push_back(input.substr(0, pos));
    input = input.substr(pos + 1);
    pos = input.find_first_of(delim);
  }
  splitArray.push_back(input.substr(0, pos));

  return splitArray;
}

}