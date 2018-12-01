#include "utils.hpp"

bool fileExists(std::string const &path) {
  struct stat buff;   
  return (stat (path.c_str(), &buff) == 0); 
}