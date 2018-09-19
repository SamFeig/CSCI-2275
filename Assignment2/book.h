/*
// Created by Sam Feig on 9/17/18.
// Books will have an ISBN number, number of pages, genre of book.
*/

#ifndef ASSIGNMENT2_BOOK_H
#define ASSIGNMENT2_BOOK_H
#import <iostream>
#include "item.h"

class book:public item {
private:
    int ISBN = 0;
    int pages = 0;
    std::string genre = "";
public:
    book();
    book(int, std::string, std::string, int, int, int, std::string);

    void setISBN(int);
    void setPages(int);
    void setGenre(std::string);

    int getISBN();
    int getPages();
    std::string getGenre();

    bool search(int);
    void printInfo();

};


#endif //ASSIGNMENT2_BOOK_H
