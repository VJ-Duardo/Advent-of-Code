#ifndef ROOMS_HPP
#define ROOMS_HPP


int getNorthPoleRoom(std::vector<std::pair<std::string, int>> &realRooms);
int getRealRoomSum(const std::vector<std::string> &lines, std::vector<std::pair<std::string, int>> &realRooms);
std::string makeCheckSum(const std::string &line);


#endif