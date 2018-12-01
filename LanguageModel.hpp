//
// Created by Victor Debray on 2018-12-01.
//

#ifndef COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP
# define COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP

# include <string>
# include <unordered_map>

class LanguageModel {
 public:
  std::unordered_map<std::string, float> _model;
  std::string _textPath;
  std::string _text;
  float _bias;

 public:
  LanguageModel(std::string const &textPath, float bias) noexcept(false);

 private:
  std::string getFileContents(std::string const &filename);
  void buildModel(std::string const &text);
};

#endif //COMP472_MINIPROJECT3_LANGUAGEMODEL_HPP
