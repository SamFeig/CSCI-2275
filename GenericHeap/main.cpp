#include <iostream>
#include "GenericHeap.cpp"

int main() {

    GenericHeap<int> h(2);
    h.push(1);
    h.push(5);
    h.printArray();
    h.push(10);
    h.push(7);
    h.printArray();
    h.push(15);

    h.printArray();
    h.heapSort();
    h.printArray();


    return 0;
}