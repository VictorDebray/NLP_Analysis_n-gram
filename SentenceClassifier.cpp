#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>

#include "SentenceClassifier.hpp"

SentenceClassifier::SentenceClassifier(int idx,
    std::string const &sentence,
    std::string const &humanReadableSentence,
    LMMap& languageModels) :
    _idx(idx),
    _sentence(sentence),
    _humanReadableSentence(humanReadableSentence),
    _languageModels(languageModels),
    _sentenceLm(_sentence)
{
    _logProbs = {
      { "french", 0 },
      { "english", 0 },
      { "other", 0 },
    };
    _sentenceLm.buildModel();
}

int SentenceClassifier::process() {
    std::string outFileName = "out" + std::to_string(_idx) + ".txt";
    std::ofstream output(outFileName);

  if (!output.is_open()) {
    std::cerr << "Couldn't open output file " << outFileName << std::endl;
    return EXIT_FAILURE;
  }

  output << _humanReadableSentence << std::endl;
  output << "UNIGRAM MODEL" << std::endl;
  
  for (char c : _sentence) {
    output << "UNIGRAM: " << c << std::endl;
  
    dumpUnigram(c, "french", std::ref(output));
    dumpUnigram(c, "english", std::ref(output));
    dumpUnigram(c, "other", std::ref(output));
  }

  auto max = std::max_element(_logProbs.begin(), _logProbs.end(),
    [] (const PMapItemType &p1, const PMapItemType &p2) {
        return p1.second < p2.second;
    });
    
  output << std::endl
    << "According to the unigram model, the sentence is in "
    << max->first
    << std::endl;

  output.close();
  return EXIT_SUCCESS;
}

void SentenceClassifier::dumpUnigram(char c, std::string const &language, std::ofstream& output) {
  float prob = _languageModels.at(language).getUnigram().getFrequency(c);
  _logProbs.at(language) += log(prob);
  std::string languageUpper;
  languageUpper.resize(language.size());
  std::transform(language.begin(), language.end(),languageUpper.begin(), ::toupper);
  
  output << languageUpper
      << ": P(" << c << ") = " 
      << prob
      << "==> log prob of sentence so far: "
      << _logProbs.at(language)
      << std::endl;
}