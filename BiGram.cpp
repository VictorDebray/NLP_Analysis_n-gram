//
// Created by Victor Debray on 2018-12-01.
//

#include "BiGram.hpp"

const int BiGram::ALONE_IDX = 26;
// Tree:
// first dimension previous letter
// second dimension current letter
// 26 letter + 1 (for letter alone) = 27
BiGram::BiGram() : _biCharAppearance(26, std::vector<int>(27, 1)), _count(0) {}

void BiGram::countChar(char histChar, char currentChar) {
  if (histChar == -1) {
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

void BiGram::populateCharCount(std::string const &text) {
  size_t len = text.size();
  size_t idx = 0;
  while (idx < len) {
    if (idx == 0)
      countChar(-1, text[idx]);
    char histChar = text[idx - 1];
    char currentChar = text[idx];
    countChar(histChar, currentChar);
    ++idx;
  }
}