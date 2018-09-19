//
// Created by Sam Feig on 9/17/18.
//

#include "magazine.h"

magazine::magazine() {}

magazine::magazine(int s, std::string n, std::string d, int p, std::string f, std::string l):item(s, n, d, p) {
    setFreq(f);
    setLocation(l);
}

void magazine::setFreq(std::string f) {
        freq = f;
}
void magazine::setLocation(std::string l) {
        location = l;
}

std::string magazine::getFreq() {
    return freq;
}
std::string magazine::getLocation() {
    return location;
}

bool magazine::search(int s) {
    if(getSerial() == s) {
        return true;
    }
    return false;
}

void magazine::printInfo() {
    std::cout<<getSerial() <<" " <<"Magazine" <<" " <<getName() <<" " <<getDate() <<" " <<getPrice() <<" " <<getFreq() <<" " <<getLocation() <<std::endl;
}