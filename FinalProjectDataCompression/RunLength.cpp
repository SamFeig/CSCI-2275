//
// Created by Sam Feig on 12/3/18.
//

#include "RunLength.h"
#include <string>
using namespace std;

string RunLength::encode(const string& str) {
    string encoding;
    int count;

    for(int i = 0; str[i]; i++) {
        count = 1;
        while(str[i] == str[i + 1]) {
            count++;
            i++;
        }
        encoding += to_string(count) + str[i];
    }
    return encoding;
}

string RunLength::decode(const string& str) {
    string decoding;
    int i = 0;
    while(i < str.length() - 1) {
        if(isdigit(str[i])) {
            int j = (int)str[i] - 48;
            while(j > 0) {
                decoding += str[i + 1];
                j--;
            }
        }
        i += 2;
    }
    return decoding;
}

