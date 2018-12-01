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
  size_t _count;

 private:
  void populateCharCount(std::string const &text);
  void countChar(char histChar, char currentChar);

 public:
  BiGram();
  int buildGram(std::ifstream &ifs);
};

#endif //COMP472_MINIPROJECT3_BIGRAM_HPP
