#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
    node* previous;

    node() {
        data = 0;
        previous =NULL;
        next = NULL;
    }
    node(int d, node* p, node* n) {
        data = d;
        previous = p;
        next = n;
    }
    static node* search(node* current, int key) {
        while(current != NULL) {
            if(current->data == key) {
                return current;
            }
            current = current->next;
        }
        std::cout<<key <<" not found"<<std::endl;
        return NULL;
    }
    static void insertAfter(node* prev, int newData) {
        if(prev == NULL) {
            printf("Can't insert after a NULL node");
            return;
        }

        node* newNode = new node();
        newNode->data = newData;
        newNode->next = prev->next;
        prev->next = newNode;
        newNode->previous = prev;

        if(newNode->next != NULL)
            newNode->next->previous = newNode;
    }
};

int main() {
    node* head;
    node* cur;
    node* one = new node(1, NULL, NULL);
    node* two = new node(2, NULL, NULL);
    node* three = new node(3, NULL, NULL);
    node* five = new node(5, NULL, NULL);
    node* six = new node(6, NULL, NULL);

    head = one;
    one->next = two;
    two->previous = one;

    two->next = three;
    three->previous = two;

    three->next = five;
    five->previous = three;

    five->next = six;
    six->previous = five;

    cur = head;
    std::cout<<"BEFORE:" <<std::endl;
    while(cur != NULL) {
        std::cout<<cur->data<<"->";
        cur = cur->next;
    }

    std::cout<<std::endl;

    node::insertAfter(node::search(head, 3), 4);

    cur = head;
    std::cout<<"AFTER:" <<std::endl;
    while(cur != NULL) {
        std::cout<<cur->data<<"->";
        cur = cur->next;
    }

    cur = head;
    while(cur != NULL) {
        cur = cur->next;
        delete cur;
    }
    return 0;
}