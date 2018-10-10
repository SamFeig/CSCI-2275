#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H

#include<string>

//only read the file 1 time. Store the file locally in a data structure. (Array, Vector, String)
//transfer data from local to a queue...enqueue/dequeue individual words, or entire message
struct node{

    std::string name;
    std::string message; //intended to hold one word
    node *next;
    node *previous;

};

class CommunicationNetwork
{
    public:
        CommunicationNetwork(int);
        virtual ~CommunicationNetwork();
        //circular queue methods
        void enqueue(std::string);
        std::string dequeue(); //should send through network, call transmit msg
        void printQueue();
        void buildNetwork();
        void printPath();
        bool queueIsFull(); //send when full
        void transmitMsg(std::string);
    private:
        node *head;
        node *tail;
        int queueSize;
        int queueHead;
        int queueTail;
        std::string *arrayQueue;
};

#endif // COMMUNICATIONNETWORK_H
