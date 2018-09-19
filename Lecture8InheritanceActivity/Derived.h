//
// Created by Rhonda Hoenigman on 9/12/18.
//

#ifndef LECTURE7CONSTRUCTORSINHERITANCE_DERIVED_H
#define LECTURE7CONSTRUCTORSINHERITANCE_DERIVED_H

#include "Base.h"
class Derived: public Base {
private:
    int cost;
    double fun;
public:
    Derived();
    Derived(int i);
    Derived(int i, int c);
    int getCost();
    double getFun();
    int getId();
    //int getId2();
};


#endif //LECTURE7CONSTRUCTORSINHERITANCE_DERIVED_H
