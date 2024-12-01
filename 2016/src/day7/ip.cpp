#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <set>

#include "day7/ip.hpp"
#include "utils/utils.hpp"


int main(){
  std::string input = utils::getFileContent("src/day7/addresses.txt");
  std::vector<std::string> lines = utils::getSplitArray(input, "\n");

  std::cout << countTSLSupport(lines) << std::endl;
  std::cout << countSSLSupport(lines) << std::endl;
  return 0;
}


int countTSLSupport(std::vector<std::string> &lines){
  return std::count_if(lines.begin(), lines.end(), [](std::string &line){
    return std::regex_search(line, std::regex("(\\w)(?!\\1)(\\w)\\2\\1"))
      && !std::regex_search(line, std::regex("\\[\\w*(\\w)(?!\\1)(\\w)\\2\\1\\w*\\]"));
  });
}


int countSSLSupport(std::vector<std::string> &lines){
  return std::count_if(lines.begin(), lines.end(), [](std::string &line){
    std::regex r("^(.*(\\w)(?!\\2)(\\w)\\2(?!\\w*\\]).*\\[\\w*(\\3\\2\\3)\\w*\\].*)$|^(.*\\[\\w*(\\w)(?!\\6)(\\w)\\6\\w*\\].*\\7\\6\\7(?!\\w*\\]).*)$");
    return std::regex_match(line, r);
  });
}