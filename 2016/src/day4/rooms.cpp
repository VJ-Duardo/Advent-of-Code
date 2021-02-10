#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

#include "day4/rooms.hpp"
#include "utils/utils.hpp"



int main(){
  std::string input = utils::getFileContent("src/day4/list.txt");
  std::vector<std::string> lines = utils::getSplitArray(input, "\n");

  std::vector<std::pair<std::string, int>> realRooms;
  std::cout << getRealRoomSum(lines, realRooms) << std::endl;

  std::cout << getNorthPoleRoom(realRooms) << std::endl;
}



int getNorthPoleRoom(std::vector<std::pair<std::string, int>> &realRooms){
  for (size_t i =0; i < realRooms.size(); i++){
    for (size_t j=0; j < realRooms[i].first.length(); j++){
      for (int k=0; k < realRooms[i].second; k++){
        char &letter = realRooms[i].first[j];
        letter++;
        if (letter > 'z'){
          letter = 'a';
        }
      }
    }
    if (realRooms[i].first.find("northpole") != std::string::npos) {
      return realRooms[i].second;
    }
  }
  return 0;
}



static bool compare(const std::pair<char, int> &a, const std::pair<char, int> &b){
  if (a.second == b.second){
    return a.first < b.first;
  } else {
    return a.second > b.second;
  }
}

std::string makeCheckSum(const std::string &line){
  std::set<char> letters(begin(line), end(line));
  std::vector<std::pair<char, int>> amounts;

  std::set<char>::iterator it = letters.begin();
  while (it != letters.end()){
    amounts.push_back(std::make_pair((*it), count(line.begin(), line.end(), (*it))));
    it++;
  }
  sort(amounts.begin(), amounts.end(), compare);

  std::string checksum;
  for (int i=0; i< 5; i++){
    checksum += amounts[i].first;
  }
  return checksum;
}


int getRealRoomSum(const std::vector<std::string> &lines, std::vector<std::pair<std::string, int>> &realRooms){
  int sum = 0;
  for (int i=lines.size()-1; i >= 0; i--){
    std::vector<std::string> parts = utils::getSplitArray(lines[i], "-");
    std::string roomName = std::accumulate(parts.begin(), parts.end()-1, std::string(""));
    std::string calculated = makeCheckSum(roomName);

    std::vector<std::string> postPart = utils::getSplitArray(parts.back(), "[]");

    if (calculated == postPart[1]){
      int num = std::stoi(postPart[0]);
      sum += num;
      realRooms.push_back(std::make_pair(roomName, num));
    }
  }

  return sum;
}