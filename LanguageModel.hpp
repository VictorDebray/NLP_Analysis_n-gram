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
  static float _delta;

  std::string _textPath;
  std::vector<int> _charAppearance;
  std::vector<float> _smoothedFrequencies;
  size_t _total;
  size_t _matrixSize;

 public:
  explicit LanguageModel(std::string const &textPath);
  int buildModel();

  void getSmoothedFrequencies();

 private:
  void populateCharCount(std::ifstream &file);
  float getSmoothedFrequency(int a);
};

#endif //COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP
