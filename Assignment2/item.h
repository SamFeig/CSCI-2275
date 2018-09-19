/*
// Created by Sam Feig on 9/12/18.
// Assignment 2
// Every item will have a serial number,
// name, published date (date, month, year) and price
*/

#ifndef ASSIGNMENT2_ITEM_H
#define ASSIGNMENT2_ITEM_H

#include <string>
#include <iostream>

class item {
private:
    int serial = 0;
    std::string name = "";
    std::string date = "";
    int price = 0;
public:
    item();
    item(int, std::string, std::string, int);

    void setSerial(int);
    void setName(std::string);
    void setDate(std::string);
    void setPrice(int);

    int getSerial();
    std::string getName();
    std::string getDate();
    int getPrice();

    void printInfo();
};


#endif //ASSIGNMENT2_ITEM_H
