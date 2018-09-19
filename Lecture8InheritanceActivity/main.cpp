#include <iostream>
#include "Base.h"
#include "Derived.h"
int main() {
    Base b;
    std::cout<<b.getId()<<std::endl;
    Derived der;
    std::cout<<der.getCost()<<std::endl;
    //derived class calls base class methods
    //to access private base variables
    //derived class can't call private base class methods
    std::cout<<der.Base::getId()<<std::endl;

    //Base constructor with arguments
    Base b2(5);
    std::cout<<b2.getId()<<std::endl;

    //derived class can call either Base constructor
    //but we need a derived constructor that does that
    Derived d2(6);
    std::cout<<d2.Base::getId()<<std::endl; //returns id from base class
    std::cout<<d2.getCost()<<std::endl; //returns id from base class

    Derived d3(45,46);
    std::cout<<d3.Base::getId()<<std::endl; //returns id from base class
    std::cout<<d3.getCost()<<std::endl; //returns id from base class

    std::cout<<d3.getString()<<std::endl;
    std::cout<<d3.getFun()<<std::endl;

    std::cout<<d3.getId() <<std::endl;
    /*Activities for Friday:
     * 1. Add a new constructor to Derived to initialize cost as
     * an argument.
     *
     * 2. Add an additional variable to Base and Derived of any type
     * and add a method to access their value in main.
     *
     * 3. Add a method to Derived to overload a Base class method.
     *
     */
    
    return 0;
}