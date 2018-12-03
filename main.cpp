#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "utils.hpp"
#include "LanguageModel.hpp"
#include "SentenceClassifier.hpp"

int classifySentences(std::string const &file, LMMap& lms) {
  std::ifstream text(file);
  if (!text.is_open()) {
    std::cerr << "Can't open file " << file << std::endl;
    return EXIT_FAILURE;
  }

  std::string chunk;
  auto idx = 1;
  while (std::getline(text, chunk)) {
    auto humanReadableSentence = chunk;
    chunk.erase(remove_if(chunk.begin(), chunk.end(), 
      [](char c) { return !isalpha(c); } ), chunk.end());
    SentenceClassifier sc(idx++, chunk, humanReadableSentence, lms);
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
  auto lm1 = LanguageModel(textPath1, "EN.txt");
  if (lm1.buildModel())
    std::cerr << "Cant open file";
  auto lm2 = LanguageModel(textPath2,"FR.txt");
  if (lm2.buildModel())
    std::cerr << "Cant open file";
  auto lm3 = LanguageModel(textPath3, "OT.txt");
  if (lm3.buildModel())
    std::cerr << "Cant open file";
  std::cout << "Model parsed" << std::endl;

  lm1.computeFrequencies();
  lm2.computeFrequencies();
  lm3.computeFrequencies();

  std::string inputFile(av[4]);
  
  std::map<std::string, LanguageModel> lms = { 
    { "english", lm1 }, 
    { "french", lm2, },
    { "other", lm3 },
  };
  return classifySentences(inputFile, lms);
}