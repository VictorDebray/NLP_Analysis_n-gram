//
// Created by Victor Debray on 2018-12-01.
//

#include <cerrno>
#include <sstream>
#include "LanguageModel.hpp"
#include "MyException.hpp"

LanguageModel::LanguageModel(std::string const &textPath, float bias) noexcept(false)
: _textPath(textPath), _bias(bias)  {
  try {
    _text = getFileContents(textPath);
  } catch (...) {
    throw MyException("Could not get file content");
  }
}

std::string LanguageModel::getFileContents(std::string const &filename) {
  std::FILE *fp = std::fopen(filename.c_str(), "rb");
  if (fp) {
    std::string contents;
    std::fseek(fp, 0, SEEK_END);
    contents.resize(std::ftell(fp));
    std::rewind(fp);
    std::fread(&contents[0], 1, contents.size(), fp);
    std::fclose(fp);
    return (contents);
  }
  throw (errno);
}

void LanguageModel::buildModel(std::string const &text) {
  std::stringstream sstream(_text);
  std::string word;

  while (sstream >> word) {
    auto it = _model.find(word);
    if (it == _model.end()) {
      _model[word] = _bias;
    }
  }
}
