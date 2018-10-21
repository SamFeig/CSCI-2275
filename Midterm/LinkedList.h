//
//  LinkedList.h
//
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct Node{
    int key;
    Node *next;
    Node *previous;
    
    Node(){}; // default constructor
    
    Node(int k, Node *n, Node *p)
    {
        key = k;
        next = n;
        previous = p;
    }
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void addNode(int prev, int k);
    void printList();
    void deleteNode(int k);
    void deleteAllNodes();

    bool isConnected(int k1, int k2);
    Node *search(int value);
protected:
private:
    Node *head;
    Node *tail;
};

#endif // LINKEDLIST_H
