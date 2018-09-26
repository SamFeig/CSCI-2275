/*
 * Created by Sam Feig on 9/19/18.
 * Assignment 3
 *
 *
 */

#include <iostream>
#include <sstream>
#include "WordAnalysis.h"

using namespace std;

int main(int argc, char* argv[]) {
    WordAnalysis a(argv[2], argv[3]);

    a.printTopN(stoi(argv[1]));

    stringstream ss(argv[4]);
    string search;

    getline(ss, search, ',');
    a.search(search);
    getline(ss, search, ',');
    a.search(search);
    return 0;
}


