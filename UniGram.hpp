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

 public:
  UniGram();
  void buildGram(std::string const &text);
};

#endif //COMP472_MINIPROJECT3_UNIGRAM_HPP
