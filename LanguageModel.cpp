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

LanguageModel::LanguageModel(std::string const &textPath, std::string const &dumpPath, float delta) :
    _textPath(textPath),
    _dumpPath(dumpPath),
    _delta(delta) {}


LanguageModel::LanguageModel(std::string const &sentence) : _sentence(sentence) {}

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

int LanguageModel::computeFrequencies() {
  _unigram.computeSmoothedFrequencies(_delta);
  _unigram.dumpSmoothedFrequencies("unigram" + _dumpPath);
  _bigram.computeSmoothedFrequencies(_delta);
  _unigram.dumpSmoothedFrequencies("bigram" + _dumpPath);
  return 0;
}

UniGram const& LanguageModel::getUnigram() const {
  return _unigram;
}

BiGram const& LanguageModel::getBigram() const {
  return _bigram;
}
