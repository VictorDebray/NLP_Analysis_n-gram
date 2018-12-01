//
// Created by Victor Debray on 2018-12-01.
//

#ifndef COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP
# define COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP

# include <string>
# include <fstream>
# include <vector>
# include <unordered_map>

class LanguageModel {
 public:
  std::string _textPath;
  std::vector<int> _charAppearance;
  float _bias;
  size_t _count;

 public:
  explicit LanguageModel(std::string const &textPath, float bias = 0.5);
  int buildModel();

 private:
  void populateCharCount(std::ifstream &file);
};

#endif //COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP
