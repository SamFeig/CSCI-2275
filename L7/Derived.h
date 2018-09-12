//
// Created by Sam Feig on 9/12/18.
//
#include "Base.h"

#ifndef L7_DERIVED_H
#define L7_DERIVED_H


class Derived:public Base {
private:
int cost;

public:
Derived();
Derived(int);
Derived(int, int);
int getCost();
};


#endif //L7_DERIVED_H
