//
// Created by Victor Debray on 2018-12-01.
//

#include <cerrno>
#include <sstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include "LanguageModel.hpp"

float LanguageModel::_delta = 0.5;

LanguageModel::LanguageModel(std::string const &textPath)
    : _textPath(textPath), _charAppearance(26, 1), _total(0) {}

int LanguageModel::buildModel() {
  std::ifstream text(_textPath);
  if (!text.is_open())
    return EXIT_FAILURE;
  populateCharCount(text);
  return 0;
}

void LanguageModel::populateCharCount(std::ifstream &file) {
  std::string chunk;
  while (std::getline(file, chunk)) {
    for (char c : chunk) {
      if (std::isalpha(c)) {
        int idx = std::toupper(c) - 'A';
        _charAppearance[idx] += 1;
        _total += 1;
      }
    }
  }
}

void LanguageModel::getSmoothedFrequencies() {
  _smoothedFrequencies.resize(_charAppearance.size());
  _matrixSize = _charAppearance.size();

  std::transform(_charAppearance.begin(), 
    _charAppearance.end(), 
    _smoothedFrequencies.begin(),
    std::bind(&LanguageModel::getSmoothedFrequency, this, std::placeholders::_1));
}

float LanguageModel::getSmoothedFrequency(int a) {
  float freq = static_cast<float>(a);

  return (freq + _delta) / (_total + _delta * _matrixSize);
}
