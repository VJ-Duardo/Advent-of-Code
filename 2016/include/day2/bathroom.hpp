#ifndef BATHROOM_HPP
#define BATHROOM_HPP


std::string getFileContent(std::string path);
std::vector<std::string> getSplitArray(std::string input, std::string delim);
std::string getBathroomCode(const std::vector<std::string> &lines, const std::vector<std::string> &keypad, const std::map<char,std::pair<int,int>> &direcs, int x, int y);


#endif