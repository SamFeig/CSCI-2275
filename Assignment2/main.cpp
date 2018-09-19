/*
// Created by Sam Feig on 9/12/18.
// Assignment 2
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <array>

#include "item.h"
#include "magazine.h"
#include "cd.h"
#include "book.h"

using namespace std;

struct type {
public:
    string type;
    int location;
};

void insertItem(string, int&, int&, int&);
item deleteItem(int, item[], int&, int&, int&, int&);
type search(int);
int shiftArray(type, int&, int&, int&);

//initialize pointers to arrays
book *book = NULL;
cd *cd = NULL;
magazine *magazine = NULL;
int bSize = 0;
int cSize = 0;
int mSize = 0;

int main(int argc, char *argv[]) {
//    open inventory.txt file and count occurances of each type of item
    ifstream myfile (argv[1]);
    string line;
    while(getline(myfile,line)) {
        stringstream ss(line);
        string temp;
        string type;

        getline(ss, temp, ',');
        getline(ss, type, ',');
        if(type == "Book") {
            bSize++;
        }
        else if(type == "CD") {
            cSize++;
        }
        else {
            mSize++;
        }
    }
    myfile.close();
//    cout<<bSize<<" "<<cSize<<" "<<mSize<<endl;

//    dynamically allocate memory of proper size for each type array with space to add values
    book = new class book[bSize+10];
    cd = new class cd[cSize+10];
    magazine = new class magazine[mSize+10];

//    read in inventory file and split into arrays of item type
//    split(argv[1]);
    ifstream myfile1 (argv[1]);
    int b = 0;
    int c = 0;
    int m = 0;
    while(getline(myfile1,line)) {
        insertItem(line, b, c, m);
    }
    myfile.close();

    ifstream myfile2 (argv[2]);
    while(!myfile2.eof()) {
        string action;
        myfile2 >> action;
//        insert
        if(action == "1") {
//            cout << "action 1" << endl;
            getline(myfile2,line); //remove excess endline character
            getline(myfile2,line); //read in item to be added
            cout<<"Inserting: "<<line <<endl;
            insertItem(line, b, c, m);
        }
//        delete
        else if(action == "2") {
//            cout << "action 2" << endl;
            myfile2 >> line;
            struct type t;
            t = search(stoi(line));
            cout<<"Found: "<<t.type<<" at location "<<t.location<<endl;
            cout<<"Removed. Size is now: "<<shiftArray(t, bSize, cSize, mSize)<<endl;
        }
//        search
        else if(action == "3"){
//            cout<<"action 3"<<endl;
            string data;
            myfile2 >> data;
            search(stoi(data));
        }
    }

//      de-allocate memory
    delete [] book;
    delete [] cd;
    delete [] magazine;
    book = NULL;
    cd = NULL;
    magazine = NULL;
    return 0;
}
void insertItem(string line, int& b, int& c, int& m) {
    stringstream ss(line);
    string serial;
    string type;
    string name;
    string date;
    string price;

    getline(ss, serial, ',');
    getline(ss, type, ',');
    getline(ss, name, ',');
    getline(ss, date, ',');
    getline(ss, price, ',');

    if (type == "Book") {
        string isbn;
        string pages;
        string genre;

        getline(ss, isbn, ',');
        getline(ss, pages, ',');
        getline(ss, genre);

        book[b].setSerial(stoi(serial));
        book[b].setName(name);
        book[b].setDate(date);
        book[b].setPrice(stoi(price));
        book[b].setISBN(stoi(isbn));
        book[b].setPages(stoi(pages));
        book[b].setGenre(genre);

//           book[b].printInfo();
//        cout<<b<<endl;
        b++;
    } else if (type == "CD") {
        string time;
        string description;
        getline(ss, time, ',');
        getline(ss, description);

        cd[c].setSerial(stoi(serial));
        cd[c].setName(name);
        cd[c].setDate(date);
        cd[c].setPrice(stoi(price));
        cd[c].setPlayTime(time);
        cd[c].setDescription(description);

//            cd[c].printInfo();
//            cout<<c<<endl;
        c++;

    } else {
        string freq;
        string location;

        getline(ss, freq, ',');
        getline(ss, location);

        magazine[m].setSerial(stoi(serial));
        magazine[m].setName(name);
        magazine[m].setDate(date);
        magazine[m].setPrice(stoi(price));
        magazine[m].setFreq(freq);
        magazine[m].setLocation(location);

//            magazine[m].printInfo();
//            cout<<m<<endl;
        m++;
    }
}

int shiftArray(type t, int& bSize, int& cSize, int& mSize) {
    if(t.type == "Book") {
        for(int i = t.location; i < bSize-1 ; i++) {
            book[i] = book[i+1];
            //items[i].printInfo();
        }
        bSize--;
        return bSize;
    }
    else if(t.type == "CD") {
        for(int i = t.location; i < cSize-1 ; i++) {
            cd[i] = cd[i+1];
            //items[i].printInfo();
        }
        cSize--;
        return cSize;

    }
    else {
        for(int i = t.location; i < mSize-1 ; i++) {
            magazine[i] = magazine[i+1];
            //items[i].printInfo();
        }
        mSize--;
        return mSize;
    }
}

type search(int s) {
    bool found = false;
    type t;
//    search books array
    int i = -1;
    while(!found && i < bSize) {
        i++;
        found = book[i].search(s);
    }
    if(found) {
        book[i].printInfo();
        t.location = i;
        t.type = "Book";
        return t;
    }
//     search cds array
    i = -1;
    while(!found && i < cSize) {
        i++;
        found = cd[i].search(s);
    }
    if(found) {
        cd[i].printInfo();
        t.location = i;
        t.type = "CD";
        return t;
    }
//    search magazine array
    i = -1;
    while (!found && i < mSize) {
        i++;
        found = magazine[i].search(s);
    }
    if(found) {
        magazine[i].printInfo();
        t.location = i;
        t.type = "Magazine";
        return t;
    }
    else {
        cout << "Not Found" << endl;
    }
    return t;
}