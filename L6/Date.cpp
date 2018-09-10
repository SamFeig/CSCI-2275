#include "Date.h"
#include <iostream>

Date::Date(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

void Date::printDate() {
    std::cout<<month <<" " <<day <<" " <<year<<std::endl;
}
void Date::setMonth(int m) {
    if (m > 0 and m < 13) {
        month = m;
    }
    else {
        std::cout<<"month out of range" <<std::endl;
    }
}

void Date::setDay(int d) {
    day = d;
}
