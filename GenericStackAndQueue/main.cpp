#include <iostream>
#include "GenericStack.cpp"

int main() {
    Stack<int> a;
    a.push(5);
   std:: cout<<a.pop();
    return 0;
}