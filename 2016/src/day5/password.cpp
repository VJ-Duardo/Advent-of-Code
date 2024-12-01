#include <iostream>
#include <string>
#include <vector>
#include <openssl/md5.h>
#include <string.h>

#include "day5/password.hpp"



int main(){
  std::string doorID = "abbhdwsy";
  
  std::cout << getPassword(doorID, false) << std::endl;
  std::cout << getPassword(doorID, true) << std::endl;
}


static void checkMD5(const char* input, std::string &password, bool part2){
  unsigned char md[MD5_DIGEST_LENGTH];
  MD5_CTX c;

  MD5_Init (&c);
  MD5_Update (&c, input, strlen(input));
  MD5_Final (md, &c);

  if (!md[0] && !md[1] && md[2] <= 15){
    std::string hash;
    char buf[MD5_DIGEST_LENGTH];
    for (int i = 0; i<MD5_DIGEST_LENGTH; i++){
        sprintf(buf, "%02x", md[i]);
        hash.append(buf);
    }
    if (part2){
      int index = hash[5]-'0';
      if(index < PASS_LEN && password[index] == '-'){
        password[index] = hash[6];
      }
    } else{
      password[password.find('-')] = hash[5];
    }
  }
}


std::string getPassword(std::string &doorID, bool part2){
  std::string password(PASS_LEN, '-');
  int num = 0;

  do {
    std::string input = doorID + std::to_string(num);
    checkMD5(input.c_str(), password, part2);
    num++;
  } while (password.find('-') != std::string::npos);
  return password;
}