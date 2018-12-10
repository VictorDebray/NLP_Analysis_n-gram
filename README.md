NLP_Analysis_n-gram

# What is this ?

This i a uni and bi-gram language model generator in c++.

It takes 3 languages corpus to build a uni and bi-gram model from and a file of sentences.

Those sentences will see their language identified by our SentenceClassfier.

We used the n-gram language model method with smoothed log probabilities. More on that in the report. (PDF file)

# How to execute our program ?

1. You must have g++ and cmake installed on the computer
2. Launch the following command:

```
$ cmake . && make && ./uni-bigram-model [path to english corpus] [path to french corpus] [path to euskara corpus] \
 [path to sentences]
````

Note : it can be any language. For simplicity we took care of taking out any diacritics