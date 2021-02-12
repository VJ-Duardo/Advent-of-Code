#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "day6/signals.hpp"
#include "utils/utils.hpp"


int main(){
  std::string input = utils::getFileContent("src/day6/messages.txt");
  std::vector<std::string> lines = utils::getSplitArray(input, "\n");

  std::cout << getErrorCorrectedVersion(lines, true) << std::endl;
  std::cout << getErrorCorrectedVersion(lines, false) << std::endl;

  return 0;
}


std::string getErrorCorrectedVersion(std::vector<std::string> &lines, bool mostCommon){
  std::string message;
  for (size_t i=0; i < lines[0].length(); i++){
    std::vector<std::pair<char, int>> chars;
    for (size_t j=0; j< lines.size(); j++){
      std::vector<std::pair<char,int>>::iterator it = 
        std::find_if(chars.begin(), chars.end(), [&](const std::pair<char,int> &p){
          return p.first == lines[j][i];
        });
      if (it != chars.end()){
        it->second++;
      } else {
        chars.push_back(std::make_pair(lines[j][i], 1));
      }
    }
    std::vector<std::pair<char, int>>::iterator best =
      std::max_element(chars.begin(), chars.end(), [&mostCommon](const std::pair<char,int> &a, const std::pair<char, int> &b)->bool{
        if (mostCommon){
          return a.second < b.second;
        } else {
          return a.second > b.second;
        }
      });
    message += best->first;
  }
  return message;
}