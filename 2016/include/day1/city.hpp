#ifndef CITY_HPP
#define CITY_HPP


enum Orientation {NORTH, EAST, SOUTH, WEST};

int getBlockDistance(std::vector<std::string> &direcs, bool part2);
std::string getFileContent(std::string path);
std::vector<std::string> splitString(std::string input, std::string delim);


#endif