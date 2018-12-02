//
// Created by Victor Debray on 2018-12-01.
//

#include <cerrno>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
#include "utils.hpp"
#include "LanguageModel.hpp"

float LanguageModel::_delta = 0.5;

LanguageModel::LanguageModel(std::string const &textPath, 
  std::string const &dumpPath,
  std::string const &language) : 
    _textPath(textPath), 
    _dumpPath(dumpPath),
    _charAppearance(26, 1), 
    _total(0),
    _language(language) {}

LanguageModel::LanguageModel(std::string const &sentence) :
    _charAppearance(26, 1), 
    _total(0),
    _sentence(sentence) {}

int LanguageModel::buildModel() {
  std::ifstream text(_textPath);
  if (!text.is_open())
    return EXIT_FAILURE;
  
  std::string chunk;
  while (std::getline(text, _sentence)) {
    populateCharCount();
  }
  
  text.close();
  return EXIT_SUCCESS;
}

void LanguageModel::populateCharCount() {
  for (char c : _sentence) {
    if (std::isalpha(c)) {
      int idx = std::toupper(c) - 'A';
      _charAppearance[idx] += 1;
      _total += 1;
    }
  }
}

void LanguageModel::getSmoothedFrequencies(bool dump) {
  _smoothedFrequencies.resize(_charAppearance.size());

  std::function<float (int)> getSmoothedfrequency = std::bind(
    [](int a, float delta, float total, int matrixSize) {
      float freq = static_cast<float>(a);
      return (freq + delta) / (total + delta * matrixSize);
    }, std::placeholders::_1, _delta, _total, _charAppearance.size()
  );

  std::transform(_charAppearance.begin(), 
    _charAppearance.end(), 
    _smoothedFrequencies.begin(),
    getSmoothedfrequency);
    
  if (dump) {
    dumpSmoothedFrequencies();
  }
}

int LanguageModel::dumpSmoothedFrequencies()
{
  std::ofstream output(_dumpPath);
  if (!output.is_open()) {
    std::cerr << "Couldn't open dump file " << _dumpPath << std::endl;
    return EXIT_FAILURE;
  }

  char idx = 'a';
  std::function<void (float)> dumpSmoothedFrequency = std::bind(
    [&idx](float item, std::ofstream& of) {
      of << "P(" << idx << ") = " << item << std::endl;
      ++idx;
    }, std::placeholders::_1, std::ref(output)
  );

  std::for_each(_smoothedFrequencies.begin(), 
    _smoothedFrequencies.end(),
    dumpSmoothedFrequency
  );

  output.close();
  return EXIT_SUCCESS;
}

