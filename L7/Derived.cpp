//
// Created by Sam Feig on 9/12/18.
//

#include "Derived.h"

Derived::Derived() {}

Derived::Derived(int i):Base(i) {}

Derived::Derived(int c, int i):Base(i) {
    cost = c;
}

int Derived::getCost() {
    return cost;
}
