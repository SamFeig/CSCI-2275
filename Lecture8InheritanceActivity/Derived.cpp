//
// Created by Rhonda Hoenigman on 9/12/18.
//

#include "Derived.h"
#include <iostream>
Derived::Derived(){

    cost = 200;
    fun = 3.1415;
    std::cout<<"derived constructor called"<<std::endl;

};

Derived::Derived(int i):Base{i}, cost(200), fun(3.1415) {

//    cost = 200;
//    fun = 3.1415;

    std::cout<<"derived constructor with arg called"<<std::endl;

};

Derived::Derived(int i, int c):Base{i}, cost(c), fun(3.1415) {
//    cost = c;
//    fun = 3.1415;
    std::cout<<"derived constructor with arg called and initialize cost as an arg"<<std::endl;
}

int Derived::getCost() {return cost;}

double Derived::getFun() {
    return fun;
}
int Derived::getId() {
    return cost;
}
//tries to access private variable in base class
//int Derived::getId2() {return id;}