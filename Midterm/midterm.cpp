//
//  midterm.cpp
//
#include <iostream>
#include "LinkedList.h"
#include "Array.h"
#include<exception>

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

//    cout<<endl<<endl<<"TEST CASES Question 1"<<endl<<endl;
//
//
//    try{
//        cout<<"Test case 1"<<endl;
//        Array q1t1(-1, 30);
//        q1t1.appendData(5);q1t1.appendData(15);q1t1.appendData(17);q1t1.appendData(2);q1t1.appendData(5);q1t1.insertData(12,1);
//        q1t1.printAboveValue(10);
//        cout<<endl;
//        //Output:   12  15  17
//    }catch(exception& e){
//        cout<<"Test case 1 has run time error"<<endl;
//    }
//
//    try{
//        cout<<"Test case 2"<<endl;
//        Array q1t2(-1, 30);
//        q1t2.appendData(5);q1t2.appendData(15);q1t2.appendData(17);q1t2.appendData(2);q1t2.appendData(5);q1t2.insertData(12,1);
//        q1t2.printAboveValue(0);
//        cout<<endl;
//        //Output:
//    }catch(exception& e){
//        cout<<"Test case 2 has run time error"<<endl;
//    }
//
//    try{
//        cout<<"Test case 3"<<endl;
//        Array q1t3(-1, 30);
//        q1t3.appendData(5);q1t3.appendData(15);q1t3.appendData(17);q1t3.appendData(2);q1t3.appendData(5);q1t3.insertData(12,1);
//        q1t3.printAboveValue(1);
//        cout<<endl;
//        //Output:   5   12  15  17  2   5
//    }catch(exception& e){
//        cout<<"Test case 3 has run time error"<<endl;
//    }
//
//    cout<<endl<<endl;

    return 0;

}
