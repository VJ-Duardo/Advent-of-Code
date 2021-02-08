#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

#include "day1/city.hpp"


int main(){
  std::string input = getFileContent("src/day1/directions.txt");
  std::vector<std::string> direcs = splitString(input, ", ");
  if (direcs.empty()) {
    return 0;
  }

  std::cout << getBlockDistance(direcs, false) << std::endl;
  std::cout << getBlockDistance(direcs, true) << std::endl;
}



int getBlockDistance(std::vector<std::string> &direcs, bool part2){
  int x = 0, y = 0;
  std::set<std::pair<int, int>> history;
  history.emplace(x, y);
  Orientation orient = NORTH;
  for (size_t i=0; i < direcs.size(); i++){
    orient = static_cast<Orientation>(((WEST+1) + ((direcs[i][0] == 'R') ? orient+1 : orient-1 % (WEST+1))) % (WEST+1));
    int distance = std::stoi(direcs[i].substr(1));
    int xc = 0, yc = 0;
    switch(orient){
      case NORTH:
        yc = 1;
        break;
      case EAST:
        xc = 1;
        break;
      case SOUTH:
        yc = -1;
        break;
      case WEST:
        xc = -1;
        break;
    }
    for (int i=0; i < distance; i++){
      x += xc;
      y += yc;
      if (part2 && !history.emplace(x, y).second){
        return abs(x) + abs(y);
      }
    }
  }
  return abs(x) + abs(y);
}



std::string getFileContent(std::string path){
  std::ifstream stream(path);
  std::string content ((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
  return content;
}


std::vector<std::string> splitString(std::string input, std::string delim){
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
