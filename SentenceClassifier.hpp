#ifndef SENTENCE_CLASSIFIER_HPP
# define SENTENCE_CLASSIFIER_HPP

# include <string>
# include <vector>
# include "utils.hpp"

using PMap = std::map<std::string, float>;

class SentenceClassifier {

private:
    std::string _sentence;
    std::string _humanReadableSentence;
    LMMap _languageModels;
    LanguageModel _sentenceLm;

    std::map<std::string, float> _logProbs;
    using PMapItemType = decltype(_logProbs)::value_type;

    int _idx;

public:
    explicit SentenceClassifier(int idx, 
        std::string const &sentence,
        std::string const &humanReadableSentence,
        LMMap& languageModels);

    int process();

private:
    void dumpUnigram(char c, std::string const &language, std::ofstream &output);
};

#endif