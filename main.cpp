#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "LanguageModel.hpp"
#include "SentenceClassifier.hpp"

int classifySentences(std::string const &file, std::vector<LanguageModel>& lm) {
  std::ifstream text(file);
  if (!text.is_open()) {
    std::cerr << "Can't open file " << file << std::endl;
    return EXIT_FAILURE;
  }

  std::string chunk;
  while (std::getline(text, chunk)) {
    SentenceClassifier sc(chunk, lm);
    sc.process();
  }

  text.close();
  return EXIT_SUCCESS;
}

int main(int ac, char **av) {
  if (ac != 5) {
    std::cerr << "Input 4 files : training texts for each language and an file containing the sentences to be classified" << std::endl;
    return EXIT_FAILURE;
  }
  std::string textPath1(av[1]);
  std::string textPath2(av[2]);
  std::string textPath3(av[3]);
  auto lm1 = LanguageModel(textPath1, "unigramEN.txt", "English");
  if (lm1.buildModel())
    std::cerr << "Cant open file";
  auto lm2 = LanguageModel(textPath2,"unigramFR.txt", "French");
  if (lm2.buildModel())
    std::cerr << "Cant open file";
  auto lm3 = LanguageModel(textPath3, "unigramOT.txt", "Other Language");
  if (lm3.buildModel())
    std::cerr << "Cant open file";
  std::cout << "Model parsed" << std::endl;

  lm1.getSmoothedFrequencies();
  lm2.getSmoothedFrequencies();
  lm3.getSmoothedFrequencies();

  std::string inputFile(av[4]);
  
  std::vector<LanguageModel> lms = { lm1, lm2, lm3 };
  return classifySentences(inputFile, lms);
}