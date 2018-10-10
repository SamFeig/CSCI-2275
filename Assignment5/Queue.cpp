//
// Created by Sam Feig on 10/6/18.
//
#include <iostream>
using namespace std;

class Queue {
public:
    int head = 0;
    int tail = 0;
    static const int maxSize = 10;
    string data[maxSize];
    int currentSize = 0; //how many items in the queue

    Queue() {}

    string dequeue() {
        string word;
        if(!isEmpty()) {
            word = data[head];
            data[head] = "";
            currentSize--;
            if(head == maxSize - 1) { //could also use mod
                head = 0;
            }
            else {
                head++;
            }
            cout<<endl;
            cout<<"H: " <<head <<endl;
            cout<<"T: " <<tail <<endl;
        }
        else {
            cout << "Queue empty" << endl;
        }
        return word;
    }

    void enqueue(string word) {
        if (!isFull()) {
            data[tail] = word;
            currentSize++;
            if (tail == maxSize - 1) {
                tail = 0;
            } else {
                tail++;
            }
            cout<<endl;
            cout<<"E: " <<word <<endl;
            cout<<"H: " <<head <<endl;
            cout<<"T: " <<tail <<endl;
        }
        else {
            cout << "Queue Full" << endl;
        }
    }

// Function displaying the elements
// of Circular Queue
    void displayQueue() {
        cout<<endl;
        if(isEmpty()) {
            cout<<"Queue is Empty" <<endl;
            return;
        }
        cout<<"Elements in Circular Queue are: " <<endl;
        if(tail > head) {
            for(int i = head; i < tail; i++)
                cout<< i <<": " <<data[i] <<endl;
        }
        else {
            for(int i = 0; i < maxSize; i++)
                cout<< i <<": " <<data[i] <<endl;

//            for(int i = 0; i <= tail; i++)
//                cout<< i <<": " <<data[i] <<endl;
        }
    }

    bool isFull() {
        if(currentSize == maxSize) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if(currentSize == 0) {
            return true;
        }
        return false;
    }
};