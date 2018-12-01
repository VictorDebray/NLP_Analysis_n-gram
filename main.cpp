#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "LanguageModel.hpp"

int main(int ac, char **av) {
  if (ac != 4) {
    std::cerr << "Input 3 files : training texts for each languages" << std::endl;
    return EXIT_FAILURE;
  }
  std::string textPath1(av[1]);
  std::string textPath2(av[2]);
  std::string textPath3(av[3]);
  auto lm1 = LanguageModel(textPath1);
  if (lm1.buildModel())
    std::cerr << "Cant open file";
  auto lm2 = LanguageModel(textPath2);
  if (lm2.buildModel())
    std::cerr << "Cant open file";
  auto lm3 = LanguageModel(textPath3);
  if (lm3.buildModel())
    std::cerr << "Cant open file";
  std::cout << "Model parsed" << std::endl;
}