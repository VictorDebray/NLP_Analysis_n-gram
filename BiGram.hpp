//
// Created by Victor Debray on 2018-12-01.
//

#ifndef COMP472_MINIPROJECT3_BIGRAM_HPP
# define COMP472_MINIPROJECT3_BIGRAM_HPP

# include <string>
# include <fstream>
# include <vector>

class BiGram {
 public:
  static const int ALONE_IDX;
 private:
  std::vector<std::vector<int>> _biCharAppearance;
  std::vector<std::vector<float>> _smoothedFrequencies;
  size_t _count;

 private:
  void countChar(char histChar, char currentChar);
  std::string epurStr(std::string const &str);

 public:
  BiGram();
  void buildGram(std::string const &text);
  void computeSmoothedFrequencies(float delta);
  float getFrequency(char histChar, char currChar) const;
  int dumpSmoothedFrequencies(std::string const &filePath);
};

#endif //COMP472_MINIPROJECT3_BIGRAM_HPP
