//
// Created by Sam Feig on 10/3/18.
//

#ifndef L16_STACK_H
#define L16_STACK_H

class Stack {
private:
    int top;
    int data;
    int maxSize;
public:
    Stack();
    bool isFull(); //could be private
    bool isEmpty(); //could be private
    void Push(Value);
    int Pop();

};


#endif //L16_STACK_H
