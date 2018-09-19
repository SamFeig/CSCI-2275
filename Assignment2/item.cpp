/*
// Created by Sam Feig on 9/12/18.
// Assignment 2
*/

#include "item.h"

item::item() {}

item::item(int s, std::string n, std::string d, int p) {
    setSerial(s);
    setName(n);
    setDate(d);
    setPrice(p);
}

void item::setSerial(int s) {
    serial = s;
}
void item::setName(std::string n) {
    name = n;
}
void item::setDate(std::string d) {
    date = d;
}
void item::setPrice(int p) {
    price = p;
}

int item::getSerial() {
    return serial;
}
std::string item::getName() {
    return name;
}
std::string item::getDate() {
    return date;
}
int item::getPrice() {
    return price;
}

void item::printInfo() {
    std::cout<<getSerial() <<" " <<"Item" <<" " <<getName() <<" " <<getDate() <<" " <<getPrice() <<std::endl;
}