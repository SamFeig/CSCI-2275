//
//  LinkedList.cpp

#include <iostream>
#include <fstream>
//#include <algorithm>

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::~LinkedList() {
    if(!this->head) {
        // nothing to delete
        return;
    }
    
    this->deleteAllNodes();
    
    this->head = nullptr;
    this->tail = nullptr;
}

void LinkedList::addNode(int prev, int k) {
    if(!this->head) {
        // no list. Create the head node
        cout<<"adding head"<<endl;
        this->head = new Node(k, nullptr, nullptr);
        this->tail = this->head;
        return;
    } 
    
    Node *ptr = this->head;
    while(ptr->key != prev) {
        ptr = ptr->next;
    }
    
    Node *newNode = new Node(k, ptr->next, ptr);
    if(ptr!=tail) {
        ptr->next->previous = newNode;
        ptr->next = newNode;
    }
    else {
        ptr->next = newNode;
        tail=newNode;
    }

}

void LinkedList::printList() {
    cout << "Current nodes" << endl;
    if (this->head == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    Node *n = this->head;
    cout << "NULL <- ";
    while(n->next) {
        cout << n->key << " <-> ";
        n = n->next;
    }
    cout << n->key << " -> NULL"<< endl;
    cout << "==================" << endl;
}

void LinkedList::deleteNode(int k) {
    Node *ptr = head;
    while(ptr && ptr->key != k) {
        ptr = ptr->next;
    }
    
    // if we reach end without finding the k node. 
    // Then nothing to delete.

    if(!ptr) 
    {
        cout << k << " not found" << endl;
        return;
    }
    if (ptr->previous) {
        // if there's a previous node.
        // This also takes care of deleting the tail. (ptr->next will be nullptr)
        ptr->previous->next = ptr->next;
    } else {
        // no previous node. Has to be head node
        head = head->next;
        if(head) head->previous = nullptr;
    }
    
    if(ptr->next) {
        // only if there is next
        ptr->next->previous = ptr->previous;
    }
    delete ptr;
}

void LinkedList::deleteAllNodes() {
    while(head) {
        cout << "deleting " << head->key << endl;
        this->deleteNode(head->key);
    }
}

Node* LinkedList::search(int value) {
    Node* current = head;
    while(current != NULL) {
        if(current->key == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

bool LinkedList::isConnected(int k1, int k2) {
    Node* n1 = search(k1);
    Node* n2 = search(k2);
    if(n1 == NULL || n2 == NULL) {
        return false;
    }

    if(n1->next == n2 || n2->previous == n1 || n2->next == n1 || n1->previous == n2) {
        return true;
    }

    return false;
}
