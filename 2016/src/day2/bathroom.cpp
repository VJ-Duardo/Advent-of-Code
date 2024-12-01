#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "day2/bathroom.hpp"


int main(){
  std::string input = getFileContent("src/day2/document.txt");
  std::vector<std::string> lines = getSplitArray(input, "\n");

  std::map<char,std::pair<int, int>> direcs;
  direcs.insert(std::make_pair('L', std::make_pair(-1, 0)));
  direcs.insert(std::make_pair('R', std::make_pair(1, 0)));
  direcs.insert(std::make_pair('U', std::make_pair(0, -1)));
  direcs.insert(std::make_pair('D', std::make_pair(0, 1)));

  std::vector<std::string> keypad = {"123", "456", "789"};
  std::cout << getBathroomCode(lines, keypad, direcs, 1, 1) << std::endl;

  keypad = {"  1  ", " 234 ", "56789", " ABC ", "  D  "};
  std::cout << getBathroomCode(lines, keypad, direcs, 2, 0) << std::endl;

}


std::string getBathroomCode(const std::vector<std::string> &lines, const std::vector<std::string> &keypad, const std::map<char,std::pair<int,int>> &direcs, int x, int y){
  std::string code;
  for (size_t i =0; i < lines.size(); i++){
    for (size_t j=0; j < lines[i].size(); j++){
      std::pair<int, int> change = direcs.find(lines[i][j])->second;
      size_t newX = x + change.first;
      size_t newY = y + change.second;
      if (newY < keypad.size() && newX < keypad[0].length() && keypad[newY][newX] != ' '){
        x = newX;
        y = newY;
      }
    }
    code += keypad[y][x];
  }
  return code;
}



std::string getFileContent(std::string path){
  std::ifstream stream(path);
  std::string content ((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
  return content;
}


std::vector<std::string> getSplitArray(std::string input, std::string delim){
  std::vector<std::string> splitArray;

  size_t pos = 0;
  pos = input.find(delim);

  while (pos != std::string::npos){
    splitArray.push_back(input.substr(0, pos));
    input = input.substr(pos + delim.length());
    pos = input.find(delim);
  }
  splitArray.push_back(input.substr(0, pos));

  return splitArray;
}