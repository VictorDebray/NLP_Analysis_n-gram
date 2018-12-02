//
// Created by Victor Debray on 2018-12-01.
//

#include <cerrno>
#include <sstream>
#include <iostream>
#include "LanguageModel.hpp"

LanguageModel::LanguageModel(std::string const &textPath, float bias)
    : _textPath(textPath), _bias(bias) {}

int LanguageModel::getFileContents(std::string const &filename) {
  std::FILE *fp = std::fopen(filename.c_str(), "rb");
  if (fp) {
    std::fseek(fp, 0, SEEK_END);
    _text.resize(std::ftell(fp));
    std::rewind(fp);
    std::fread(&_text[0], 1, _text.size(), fp);
    std::fclose(fp);
  } else
    return EXIT_FAILURE;
  return 0;
}

int LanguageModel::buildModel() {
  if (getFileContents(_textPath))
    return EXIT_FAILURE;
  _unigram.buildGram(_text);
  _bigram.buildGram(_text);
  return 0;
}
