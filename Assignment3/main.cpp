/*
 * Created by Sam Feig on 9/19/18.
 * Assignment 3
 *
 *
 */

#include <iostream>
#include <sstream>
#include "WordAnalysis.h"

#include <chrono>

using namespace std;

int main(int argc, char* argv[]) {
    auto start = chrono::high_resolution_clock::now();

    WordAnalysis a(argv[2], argv[3]);

    a.printTopN(stoi(argv[1]));

    stringstream ss(argv[4]);
    string search;

    getline(ss, search, ',');
    a.search(search);
    getline(ss, search, ',');
    a.search(search);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout <<"Time taken by function: " <<duration.count()/1000.0 <<" seconds" << endl;
    return 0;
}


