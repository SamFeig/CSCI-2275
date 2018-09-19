/*
// Created by Sam Feig on 9/17/18.
// CDs will have play time and description.
*/

#ifndef ASSIGNMENT2_CD_H
#define ASSIGNMENT2_CD_H
#include "item.h"

class cd:public item {
private:
    std::string playTime = "";
    std::string description = "";
public:
    cd();
    cd(int, std::string, std::string, int, std::string, std::string);

    void setPlayTime(std::string);
    void setDescription(std::string);

    std::string getPlayTime();
    std::string getDescription();

    bool search(int);
    void printInfo();
};


#endif //ASSIGNMENT2_CD_H
