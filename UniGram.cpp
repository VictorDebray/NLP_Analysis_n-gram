//
// Created by Victor Debray on 2018-12-01.
//

#include <iostream>
#include "UniGram.hpp"

UniGram::UniGram() :
    _charAppearance(26, 1),
    _smoothedFrequencies(26, 1),
    _count(0) {}

void UniGram::buildGram(std::string const &text) {
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

void UniGram::computeSmoothedFrequencies(float delta) {
  std::function<float(int)> getSmoothedfrequency = std::bind(
      [](int a, float delta, float total, int matrixSize) {
        float freq = static_cast<float>(a);
        return (freq + delta) / (total + delta * matrixSize);
      }, std::placeholders::_1, delta, _count, _charAppearance.size()
  );

  std::transform(_charAppearance.begin(),
                 _charAppearance.end(),
                 _smoothedFrequencies.begin(),
                 getSmoothedfrequency);
}

int UniGram::dumpSmoothedFrequencies(std::string const &filePath) {
  std::ofstream output(filePath);
  if (!output.is_open()) {
    std::cerr << "Couldn't open dump file " << filePath << std::endl;
    return EXIT_FAILURE;
  }

  char idx = 'a';
  std::function<void(float)> dumpSmoothedFrequency = std::bind(
      [&idx](float item, std::ofstream &of) {
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

float UniGram::getFrequency(char c) const {
  return _smoothedFrequencies.at(std::toupper(c) - 'A');
}
