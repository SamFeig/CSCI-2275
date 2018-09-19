//
// Created by Rhonda Hoenigman on 9/12/18.
//

#ifndef LECTURE7CONSTRUCTORSINHERITANCE_BASE_H
#define LECTURE7CONSTRUCTORSINHERITANCE_BASE_H
#include <iostream>

class Base {
private:
    int id;
    std::string string;
private:
    void printId();
public:
    Base();
    Base(int i); //add constructor with int argument
    int getId();
    std::string getString();
};


#endif //LECTURE7CONSTRUCTORSINHERITANCE_BASE_H
