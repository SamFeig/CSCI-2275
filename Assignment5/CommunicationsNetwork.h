//  Assignment4.h
//  Assignment4
//
//

#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H

#include <iostream>
#include <vector>
#include "Queue.cpp"
#include "LinkedList.cpp"

class CommunicationNetwork {
public:
    CommunicationNetwork(char*[]);
    ~CommunicationNetwork();
    void printMenu();
    void readFile(std::string);
    void transmitBufferedMsg();
private:
    std::vector<std::string> msg;
    Queue queue;
    LinkedList network;
    int wordLoc = 0;
};

#endif // COMMUNICATIONNETWORK_H

//struct City {
//    std::string cityName;
//    std::string message;
//    City *next;
//    City *previous;
//
//    City(){}; // default constructor
//
//    City(std::string initName, City *initNext, City *initPrevious, std::string initMessage) {
//        cityName = initName;
//        next = initNext;
//        previous = initPrevious;
//        message = initMessage;
//    }
//};
//
//void addCity(std::string, std::string);
//    void buildNetwork();
//    void transmitMsg(std::string); //this is like a string
//    void printNetwork();
//    void deleteCity(std::string);
//    void clearNetwork();
//    City* search(std::string);
//
//private:
//    City *head;
//    City *tail;
