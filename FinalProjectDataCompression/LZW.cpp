//
// Created by Sam Feig on 12/3/18.
//

#include "LZW.h"
#include "Util.cpp"
#include <iostream>

void LZW::printMap(unordered_map<string, int> dictionary) const {
    for(auto it = dictionary.begin(); it != dictionary.end(); ++it) {
        if (it->second > 255)
            cout << endl << it->first << " :: " << it->second;
    }
}

string LZW::encode(const string &data) const {
    // Build the dictionary.
    int dictSize = 256;
    unordered_map<string, int> dictionary(MAX_DEF);
    for(int i = 0; i < 256; i++) {
        dictionary[string(1, i)] = i;
    }

    stringstream encoded_stream;
    string w;
    for(string::const_iterator it = data.begin(); it != data.end(); ++it) {
        char c = *it;
        string wc = w + c;
        if (dictionary.count(wc))
            w = wc;
        else {
            encoded_stream << dictionary[w];
            encoded_stream << ' ';
//            cout<< dictionary[w] <<endl;
            // Add wc to the dictionary.
            if(dictSize == MAX_DEF) {
                dictionary.clear();
                for(int i = 0; i < 256; i++) {
                    dictionary[string(1, i)] = i;
                }
                dictSize = 256;
            }

            dictionary[wc] = dictSize++;
            w = string(1, c);
        }
    }

    // Output the code for w.
    if (!w.empty())
        encoded_stream << dictionary[w];

////    ------------------------------------------
//    ofstream file("LZWMap.txt");
//    stringstream tmp;
//    for(auto it = dictionary.begin(); it != dictionary.end(); ++it) {
//        tmp << it->second << " :: " << it->first << endl;
//    }
//    copy(tmp.str().begin(), tmp.str().end(), ostream_iterator<unsigned char>(file));
//    file.close();
////    ------------------------------------------

    return encoded_stream.str();
}

string LZW::decode(const string &data) const {
    // Build the dictionary.
    int dictSize = 256;
    map<int,std::string> dictionary;
    for (int i = 0; i < 256; i++)
        dictionary[i] = string(1, i);

    string w;
    string entry;
    string decoded_data;
    int k;
    string sk;
//    for(string::const_iterator it = data.begin(); it != data.end(); ++it) {
//    for(int i = 0; i < data.length()-1; i++) {
        stringstream ss;
        ss << data;
        getline(ss, sk, ' ');
        k = stoi(sk);
        w = k;
        decoded_data += w;

        while(ss.good()) {
            getline(ss, sk, ' ');
            k = stoi(sk);
//            cout << k << endl;

            if (dictionary.count(k))
                entry = dictionary[k];
            else if (k == dictSize)
                entry = w + w[0];
            else
                throw runtime_error("Exception: Bad compression.");

            decoded_data += entry;
            dictionary[dictSize++] = w + entry[0];
            w = entry;
        }

    return decoded_data;
}