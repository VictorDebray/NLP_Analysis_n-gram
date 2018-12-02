//
// Created by Victor Debray on 2018-12-01.
//

#include <sstream>
#include "BiGram.hpp"

const int BiGram::ALONE_IDX = 26;
// Tree:
// first dimension previous letter
// second dimension current letter
// 26 letter + 1 (for letter alone) = 27
BiGram::BiGram() : _biCharAppearance(26, std::vector<int>(27, 1)), _count(0) {}

void BiGram::countChar(char histChar, char currentChar) {
  if (histChar == -1 && std::isalpha(currentChar)) {
    int firstIdx = std::toupper(currentChar) - 'A';
    _biCharAppearance[firstIdx][BiGram::ALONE_IDX] += 1;
    _count += 1;
  } else if (std::isalpha(histChar) && std::isalpha(currentChar)) {
    int firstIdx = std::toupper(currentChar) - 'A';
    int secIdx = std::toupper(histChar) - 'A';
    _biCharAppearance[firstIdx][secIdx] += 1;
    _count += 1;
  }
}

std::string BiGram::epurStr(std::string const &str) {
  std::string epured;

  epured.reserve(str.size());
  for (char i : str) {
    if (std::isalpha(i))
      epured += i;
  }
  return epured;
}

void BiGram::buildGram(std::string const &text) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(text);
  while (tokenStream >> token) {
    tokens.push_back(token);
  }
  for (auto &it: tokens) {
    std::string word = epurStr(it);
    size_t len = word.size();
    for (size_t i = 0; i < len; i++) {
      if (i == 0)
        countChar(-1, word[i]);
      else {
        char histChar = word[i - 1];
        char currentChar = word[i];
        countChar(histChar, currentChar);
      }
    }
  }
}