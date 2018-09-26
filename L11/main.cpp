#include <iostream>
#include "LinkedList.h"

struct node {
    int data;
    node* next;
    node* previous;
    node() {}
    node(int d, node* p, node* n) {
        data = d;
        previous = p;
        next = n;
    }
    static void search(node* current, int key) {
        while(current != NULL) {
            if(current->data == key) {
                std::cout<<current->data<<std::endl;
            }
            current = current->next;
        }
        std::cout<<key <<" not found"<<std::endl;
    }
};

int main() {
   int  a[5] = {1,2,3,4,5};

   node *head = new node(1, NULL, NULL);
   node *current = head;

   for(int i = 1; i < 5; i++) {
       node *n = new node(a[i], NULL, NULL);
       current->next = n;
       current = n;

   }

   current = head;
   node::search(current, 8);

   return 0;
}