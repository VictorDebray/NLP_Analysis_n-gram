//
// Created by Victor Debray on 2018-12-01.
//

#include <cerrno>
#include <sstream>
#include <iostream>
#include "LanguageModel.hpp"

LanguageModel::LanguageModel(std::string const &textPath, float bias)
    : _textPath(textPath), _charAppearance(26, 1), _bias(bias), _count(0) {}

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
        _count += 1;
      }
    }
  }
}
