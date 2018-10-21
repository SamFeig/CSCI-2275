//
//  midterm.cpp
//
#include <iostream>

#include "LinkedList.h"
#include "Array.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    LinkedList ll;

    ll.addNode(0,5);
    ll.addNode(5,6);
    ll.addNode(6,7);
    ll.printList();
    cout<<"5,6: "<<ll.isConnected(5,6) <<endl;
    cout<<"5,7: "<<ll.isConnected(5,7)<<endl;
    cout<<"5,9: "<<ll.isConnected(5,9)<<endl;
    cout<<"8,9: "<<ll.isConnected(8,9)<<endl;
    cout<<"6,5: "<<ll.isConnected(6,5) <<endl;

    cout<<endl;
    
    Array myArray(0, 30);
    myArray.appendData(5);
    myArray.appendData(6);
    myArray.appendData(7);
    myArray.appendData(8);
    myArray.appendData(9);
    myArray.appendData(10);
    myArray.appendData(11);

    myArray.printData();
    cout<<endl;

    cout<<"Above 7: "<<endl;
    myArray.printAboveValue(7);
    cout<<"Above 3: "<<endl;
    myArray.printAboveValue(3);
    cout<<"Above 12: "<<endl;
    myArray.printAboveValue(12);

    return 0;

}
