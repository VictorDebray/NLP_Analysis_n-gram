#ifndef SENTENCE_CLASSIFIER_HPP
# define SENTENCE_CLASSIFIER_HPP

# include <string>
# include <vector>
# include "LanguageModel.hpp"

class SentenceClassifier {

private:
    std::string _sentence;
    std::vector<LanguageModel> _languageModels;

public:
    explicit SentenceClassifier(std::string const &sentence,
        std::vector<LanguageModel>& languageModels);

    void process();
};

#endif