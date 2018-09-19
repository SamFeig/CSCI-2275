//
// Created by Sam Feig on 9/17/18.
//

#include "book.h"

book::book() {}

book::book(int s, std::string n, std::string d, int p, int i, int page, std::string g):item(s, n, d, p) {
    setISBN(i);
    setPages(page);
    setGenre(g);
}

void book::setISBN(int i) {
    ISBN = i;
}
void book::setPages(int p) {
    pages = p;
}
void book::setGenre(std::string g) {
    genre = g;
}

int book::getISBN() {
    return ISBN;
}
int book::getPages() {
    return pages;
}
std::string book::getGenre() {
    return genre;
}

bool book::search(int s) {
    if(getSerial() == s) {
        return true;
    }
    return false;
}
void book::printInfo() {
    std::cout<<getSerial() <<" " <<"Book" <<" " <<getName() <<" " <<getDate() <<" " <<getPrice() <<" " <<getISBN() <<" " <<getPages() <<" " <<getGenre() <<std::endl;
}