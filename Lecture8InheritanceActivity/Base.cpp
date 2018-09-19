//
// Created by Rhonda Hoenigman on 9/12/18.
//

#include "Base.h"
#include <iostream>
Base::Base(): id(100), string("string"){
//    id = 100;
//    string = "string";
    std::cout<<"base constructor called"<<std::endl;

};
Base::Base(int i): id(i), string("string"){
//    id = i;
//    string = "string";
    std::cout<<"base constructor with arg called"<<std::endl;

}
int Base::getId() {return id;};

//private method
void Base::printId() {
    std::cout<<id<<std::endl;
}

std::string Base::getString() {
    return string;
}
