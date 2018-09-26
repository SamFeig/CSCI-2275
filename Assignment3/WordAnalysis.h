//
// Created by Sam Feig on 9/19/18.
// Should store an array of the above struct
// Should store an array of the 50 stop words
// Should also have functions that are given below
//

#ifndef ASSIGNMENT3_WORDANALYSIS_H
#define ASSIGNMENT3_WORDANALYSIS_H

#include <iostream>
using namespace std;

class WordAnalysis {
public:
    struct wordItem {
        string word = "";
        int count = 0;
    };
    WordAnalysis(string, string);
    ~WordAnalysis();
    bool isStopWord(string);
    void printTopN(int);
    int searchCount(string);
    void search(string);

private:
    int size = 100;
    int stopSize = 0;
    int cur = 0;
    int numUniqueWords = 0;
    int numDoublings = 0;
    int numTotalWords = 0;
    wordItem* array;
    string* stopWords;
    wordItem* doubleArray(wordItem[], int&, int);
    void readStopWords(string);
    void readFile(string);
    void addWord(string);
};

#endif //ASSIGNMENT3_WORDANALYSIS_H
