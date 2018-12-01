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

 private:
  void populateCharCount(std::string const &text);


 public:
  UniGram();
};

#endif //COMP472_MINIPROJECT3_UNIGRAM_HPP
