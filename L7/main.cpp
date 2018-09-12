//
// Created by Sam Feig on 9/12/18.
//
#include <iostream>
#include "Base.h"
#include "Derived.h"

int main() {
    Base b;
    std::cout <<b.getID() <<std::endl; //print ID from base class
    Derived d;
    std::cout <<d.getCost() <<std::endl; //print Cost from Derived class
    std::cout <<d.getID() <<std::endl; //print ID from base class

    Derived d2(5);
    std::cout <<d2.getCost() <<std::endl; //print Cost from Derived class
    std::cout <<d2.getID() <<std::endl; //print ID from base class

    Derived d3(20,21);
    std::cout <<d3.getCost() <<std::endl; //print Cost from Derived class
    std::cout <<d3.getID() <<std::endl; //print ID from base class
}