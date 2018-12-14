//
// Created by Sam Feig on 12/3/18.
//

#ifndef FINALPROJECTDATACOMPRESSION_RUNLENGTH_H
#define FINALPROJECTDATACOMPRESSION_RUNLENGTH_H

#include <iostream>
using namespace std;

class RunLength {
private:

public:
    string encode(const string& str);
    string decode(const string& str);
};


#endif //FINALPROJECTDATACOMPRESSION_RUNLENGTH_H
