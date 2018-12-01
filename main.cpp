#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


int main(int ac, char **av) {
  if (ac != 4) {
    std::cerr << "Input 3 files : training texts for each languages" << std::endl;
    return EXIT_FAILURE;
  }
  std::string textPath1(av[1]);
  std::string textPath2(av[2]);
  std::string textPath3(av[3]);
}