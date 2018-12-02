//
// Created by Victor Debray on 2018-12-01.
//

#ifndef COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP
# define COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP

# include <string>
# include <fstream>
# include <vector>
# include "UniGram.hpp"
# include "BiGram.hpp"

class LanguageModel {
 public:
  UniGram _unigram;
  BiGram _bigram;
  std::string _textPath;
  std::string _text;
  float _bias;

 public:
  explicit LanguageModel(std::string const &textPath, float bias = 0.5);
  int buildModel();

 private:
  int getFileContents(std::string const &file);

};

#endif //COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP
