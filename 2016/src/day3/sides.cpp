#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "day3/sides.hpp"
#include "day3/Triangle.hpp"


int main(){
  std::string input = getFileContent("src/day3/triangles.txt");
  std::vector<Triangle> triangles = createTriangles(input, true);

  std::cout << count(triangles.begin(), triangles.end(), true) << std::endl;
}



std::vector<Triangle> createTriangles(std::string &input, bool part2){
  std::vector<Triangle> triangles;
  std::vector<std::string> numbers = getSplitArray(input, " \n");
  if (!part2){
    for (size_t i =0; i < numbers.size(); i+=3){
      triangles.push_back(Triangle(std::stoi(numbers[i]), std::stoi(numbers[i+1]), std::stoi(numbers[i+2])));
    }
  } else {
    for (size_t i =0; i < numbers.size(); i++){
      triangles.push_back(Triangle(std::stoi(numbers[i]), std::stoi(numbers[i+3]), std::stoi(numbers[i+6])));
      if (i % 3 == 2){
        i += 6;
      }
    }
  }
  return triangles;
}


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