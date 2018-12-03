//
// Created by Victor Debray on 2018-12-01.
//

#include <functional>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "BiGram.hpp"

const int BiGram::ALONE_IDX = 26;
// Tree:
// first dimension previous letter
// second dimension current letter
// 26 letter + 1 (for letter alone) = 27
BiGram::BiGram() :
    _biCharAppearance(26, std::vector<int>(27, 1)),
    _smoothedFrequencies(26, std::vector<float>(27, 1.0)),
    _count(0) {
}

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

void BiGram::computeSmoothedFrequencies(float delta) {
  int matrixSize = _biCharAppearance.size() * (_biCharAppearance.size() + 1);
  std::function<float(int)> getSmoothedfrequency = std::bind(
      [](int a, float delta, float total, int matrixSize) {
        float freq = static_cast<float>(a);
        return (freq + delta) / (total + delta * matrixSize);
      }, std::placeholders::_1, delta, _count, matrixSize
  );

  for (int i = 0; i < _biCharAppearance.size(); i++) {
    std::transform(_biCharAppearance[i].begin(),
                   _biCharAppearance[i].end(),
                   _smoothedFrequencies[i].begin(),
                   getSmoothedfrequency);
  }
}

float BiGram::getFrequency(char histChar, char currChar) const {
  int currCharIdx = std::toupper(currChar) - 'A';
  int histCharIdx = 0;
  if (histChar == -1)
    histCharIdx = BiGram::ALONE_IDX;
  else
    histCharIdx = std::toupper(histChar) - 'A';
  return _smoothedFrequencies.at(currCharIdx).at(histCharIdx);
}

int BiGram::dumpSmoothedFrequencies(std::string const &filePath) {
  std::ofstream output(filePath);
  if (!output.is_open()) {
    std::cerr << "Couldn't open dump file " << filePath << std::endl;
    return EXIT_FAILURE;
  }

  char rowIdx = 'a';
  char colIdx = rowIdx;
  std::function<void (float)> dumpSmoothedFrequency = std::bind(
    [&rowIdx, &colIdx](float item, std::ofstream &of) {
      // of << "P(" << rowIdx << "|" << colIdx << ") = " << item << std::endl;
      of << "P(" << colIdx << "|" << rowIdx << ")," << item << std::endl;
      ++rowIdx;
    }, std::placeholders::_1, std::ref(output)
  );

  for (int prevCharIdx = 0; prevCharIdx < _smoothedFrequencies.size(); prevCharIdx++) {
    for (int currCharIdx = 0; currCharIdx < _smoothedFrequencies.size(); currCharIdx++) {
      auto item = _smoothedFrequencies.at(currCharIdx).at(prevCharIdx);
      char currLetter = currCharIdx + 'a';
      char prevLetter = prevCharIdx + 'a';
      output << "P(" << currLetter << "|" << prevLetter << ")," << item << std::endl;
    }
  }  


  //   std::for_each(_smoothedFrequencies.at(colIdx - 'a').begin(),
  //                 _smoothedFrequencies.at(colIdx - 'a').end() - 1,
  //                 dumpSmoothedFrequency);
  //   ++colIdx;
  //   rowIdx = 'a';
  // }

}