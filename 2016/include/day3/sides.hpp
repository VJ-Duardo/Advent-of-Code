#ifndef SIDES_HPP
#define SIDES_HPP

#include "Triangle.hpp"

std::vector<Triangle> createTriangles(std::string &input, bool part2);
std::string getFileContent(std::string path);
std::vector<std::string> getSplitArray(std::string input, std::string delim);


#endif