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
  float _delta;
  std::string _dumpPath;
  std::string _sentence;

  std::string _dumpPath;

  std::string _sentence;

 public:
  /* Overload for multi-line files */
  LanguageModel(std::string const &textPath,
    std::string const &dumpPath, float delta = 0.5);

  /* Overload for single-line sentences */
  explicit LanguageModel(std::string const &sentence);

  int buildModel();
  int computeFrequencies();
  UniGram const& getUnigram() const;
  BiGram const& getBigram() const;

  void getSmoothedFrequencies(bool dump);

 private:
  int getFileContents(std::string const &file);

};

#endif //COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP
