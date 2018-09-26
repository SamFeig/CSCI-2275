//
// Created by Sam Feig on 9/19/18.
//

#include "WordAnalysis.h"
#include <iostream>
#include <fstream>
using namespace std;

WordAnalysis::WordAnalysis(string s, string s2) {
    array = new wordItem[size];
    stopWords = new string[50];

    //read ignoreWords file
    readStopWords(s2);

    //read HungerGames file
    readFile(s);

    //sort array based on count of words
    sort(array, array+size, [](wordItem a, wordItem b){ return a.count > b.count; });
}

//Destructor to free memory of arrays
WordAnalysis::~WordAnalysis() {
    delete [] array;
    delete [] stopWords;
}

/**
* Function name: isStopWord
* Purpose: to see if a word is a stop word
* @param word - a word (which you want to check if it is a stop word)
* @return - true (if word is a stop word), or false (otherwise)
*/
bool WordAnalysis::isStopWord(string word){
    for(int i = 0; i < stopSize; i++) {
//      cout<<"checking "<<word<<" against: "<<stopWords[i]<<endl;
        if (word == stopWords[i]) {
//            cout<<"stop word: "<<word<<endl;
            return true;
        }
    }
    return false;
}

/**
* Function name: printTopN
* Purpose: to print the top N high frequency words from a sorted array
* @param topN - the number of top frequency words to print
* @return none
*/
void WordAnalysis::printTopN(int topN) {
    for(int i = 0; i < topN; i++) {
        cout<<array[i].count <<" - " <<array[i].word <<endl;
    }

    cout<<"#"<<endl;
    cout<<"Array doubled: " <<numDoublings <<endl;
    cout<<"#"<<endl;
    cout<<"Unique non-common words: " <<numUniqueWords <<endl;
    cout<<"#"<<endl;
    cout<<"Total non-common words: " <<numTotalWords <<endl;
    cout<<"#"<<endl;
}

/**
* Function name: searchCount
* Purpose: To search the count of a given word
* @param wordItemList - a pointer that points to a array of wordItems * @param word - the
words to search
* @return int – Count of the given word. Will return -1 if not found
*/
int WordAnalysis::searchCount(string word) {
    for(int i = 0; i < size; i++) {
        if(array[i].word == word) {
            return i;
        }
    }
    return -1;
}

/**
* Function name: addWord
* Purpose: To take in a string and add it to the array of struct. This function should call an
internal private function which will handle the array doubling. It should also check if the
word exists and only increase the count if it does. The word should be added in a sorted
location.
* @param word - the words to search
* @return None
*/
void WordAnalysis::addWord(string word) {
    if(cur == size) {
        array = doubleArray(array, size, cur);
    }

    //if stop word dont do anything
    if(isStopWord(word)) {
        return;
    }
    //if not stop word go through array
    else {
        int loc = searchCount(word);
        //if word already in array, increment counter
        if(loc != -1) {
            array[loc].count++;
        }
        //if word not in array add it to array
        else {
            array[cur].word = word;
            array[cur].count++;
            numUniqueWords++;
            cur++;
        }
        numTotalWords++;
    }
}

//double array if full
WordAnalysis::wordItem* WordAnalysis::doubleArray(wordItem array[], int& size, int number) {
    size = size * 2;
    wordItem *tmp = new wordItem[size];
    for(int i = 0; i < number; i++) {
        tmp[i].word = array[i].word;
        tmp[i].count = array[i].count;
    }
    numDoublings++;
    delete [] array;
    return tmp;
}

//read hungerGames text file and add words to array
void WordAnalysis::readFile(string s) {
    ifstream file(s);
    string line;
    string word;
    while(file >> word) {
        addWord(word);
    }
}

//search array for specific word
void WordAnalysis::search(string word) {
    for(int i = 0; i < size; i++) {
        if(array[i].word == word) {
            cout<<array[i].word <<" - " <<array[i].count <<endl;
        }
    }
}
//read ignoreWords text file and add words to stopWords array
void WordAnalysis::readStopWords(string s) {
    ifstream file(s);
    string line;
    while(file >> line) {
        stopWords[stopSize] = line;
        stopSize++;
    }
}