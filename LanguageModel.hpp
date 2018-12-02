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
  std::string _language;

  static float _delta;

  std::string _textPath;
  std::vector<int> _charAppearance;
  std::vector<float> _smoothedFrequencies;
  size_t _total;

  std::string _dumpPath;

  std::string _sentence;

 public:
  /* Overload for multi-line files */
  explicit LanguageModel(std::string const &textPath, 
    std::string const &dumpPath,
    std::string const &language);

  /* Overload for single-line sentences */
  explicit LanguageModel(std::string const &sentence);

  int buildModel();
  void populateCharCount();

  void getSmoothedFrequencies(bool dump);

 private:
  int dumpSmoothedFrequencies();

};

#endif //COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP
