//
// Created by Sam Feig on 9/17/18.
//

#include "cd.h"

cd::cd(){}

cd::cd(int s, std::string n, std::string d, int p, std::string t, std::string desc):item(s, n, d, p) {
    setPlayTime(t);
    setDescription(desc);
}

void cd::setPlayTime(std::string t) {
    playTime = t;
}
void cd::setDescription(std::string desc) {
    description = desc;
}

std::string cd::getPlayTime() {
    return playTime;
}
std::string cd::getDescription() {
    return description;
}

bool cd::search(int s) {
    if(getSerial() == s) {
        return true;
    }
    return false;
}

void cd::printInfo() {
    std::cout<<getSerial() <<" " <<"CD" <<" " <<getName() <<" " <<getDate() <<" " <<getPrice() <<" " <<getPlayTime() <<" " <<getDescription() <<std::endl;
}