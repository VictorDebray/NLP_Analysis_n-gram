#include "SentenceClassifier.hpp"

SentenceClassifier::SentenceClassifier(std::string const &sentence,
    std::vector<LanguageModel>& languageModels) :
    _sentence(sentence),
    _languageModels(languageModels),
    _sentenceLm(_sentence)
{
    _sentenceLm.populateCharCount();
    _sentenceLm.getSmoothedFrequencies(false);
}

void SentenceClassifier::process() {

}

