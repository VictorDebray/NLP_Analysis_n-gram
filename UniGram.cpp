//
// Created by Victor Debray on 2018-12-01.
//

#include "UniGram.hpp"

UniGram::UniGram() : _charAppearance(26, 1), _count(0) {}

void UniGram::populateCharCount(std::string const &text) {
  size_t len = text.size();
  size_t idx = 0;
  while (idx < len) {
    char c = text[idx];
    if (std::isalpha(c)) {
      int idx = std::toupper(c) - 'A';
      _charAppearance[idx] += 1;
      _count += 1;
    }
    ++idx;
  }
}
