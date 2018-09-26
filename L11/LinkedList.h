//
// Created by Sam Feig on 9/21/18.
//

#ifndef L11_LINKEDLIST_H
#define L11_LINKEDLIST_H


class LinkedList {
    struct node {
        int data;
        node* next;
        node* previous;
        node(int d, node* n) {
            data = d;
            next = n;
        }
    };



};


#endif //L11_LINKEDLIST_H
