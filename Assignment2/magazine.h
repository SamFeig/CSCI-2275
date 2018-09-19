/*
// Created by Sam Feig on 9/17/18.
// Magazines will have its frequency of publishing
// and weather it is a local or international magazine.
*/

#ifndef ASSIGNMENT2_MAGAZINE_H
#define ASSIGNMENT2_MAGAZINE_H
#include "item.h"


class magazine:public item{
private:
    std::string freq = "";
    std::string location = "";
public:
    magazine();
    magazine(int, std::string, std::string, int, std::string, std::string);

    void setFreq(std::string);
    void setLocation(std::string);

    std::string getFreq();
    std::string getLocation();

    bool search(int);
    void printInfo();
};


#endif //ASSIGNMENT2_MAGAZINE_H
