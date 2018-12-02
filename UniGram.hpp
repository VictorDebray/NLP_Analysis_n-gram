//
// Created by Victor Debray on 2018-12-01.
//

#ifndef COMP472_MINIPROJECT3_UNIGRAM_HPP
#define COMP472_MINIPROJECT3_UNIGRAM_HPP

# include <string>
# include <fstream>
# include <vector>

class UniGram {
 private:
  std::vector<int> _charAppearance;
  size_t _count;
  std::vector<float> _smoothedFrequencies;

 public:
  UniGram();
  void buildGram(std::string const &text);
  void computeSmoothedFrequencies(float delta);
  int dumpSmoothedFrequencies(std::string const &filePath);
  float getFrequency(char c) const;
};

#endif //COMP472_MINIPROJECT3_UNIGRAM_HPP
