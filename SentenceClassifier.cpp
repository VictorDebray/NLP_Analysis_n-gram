#include "SentenceClassifier.hpp"

SentenceClassifier::SentenceClassifier(std::string const &sentence,
    std::vector<LanguageModel>& languageModels) :
    _sentence(sentence),
    _languageModels(languageModels)
{}

void SentenceClassifier::process() {
    
}

