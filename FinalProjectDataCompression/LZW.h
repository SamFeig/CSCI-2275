//
// Created by Sam Feig on 12/3/18.
//

#ifndef FINALPROJECTDATACOMPRESSION_LZW_H
#define FINALPROJECTDATACOMPRESSION_LZW_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <bitset>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

#define MAX_DEF 4096

class LZW {
public:
    string encode(const string& data) const;
    string decode(const string& data) const;
    void printMap(unordered_map<string, int> dictionary) const;
};


#endif //FINALPROJECTDATACOMPRESSION_LZW_H
