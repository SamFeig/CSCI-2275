#include <iostream>
#include <exception>
#include "BST.cpp"
using namespace std;

int main() {
//    BST<int, int> st;
//    st.insert(2, 2);
//    st.insert(7, 7);
//    st.insert(4, 4);
//    st.insert(6, 6);
//    cout<<st.get(2)<<endl;
//    st.insert(1, 1);
//    st.printInorder();
//    cout<<endl;
//    st.printPostorder();
//    cout<<endl;
//    st.printPreorder();
//    cout<<endl;

    try {
        cout<<"Test case 1: Null Value insert"<<endl;
        BST<int, int> st1;
        st1.insert(NULL, NULL);
    }
    catch (exception& e) {
        cout<<e.what()<<endl;
        cout<<"Test case 1 run tiume error"<<endl;

    }
    cout<<endl;

    try {
        cout<<"Test case 2: Insert root"<<endl;
        BST<int, int> st2;
        st2.insert(2, 2);
    }
    catch (exception& e) {
        cout<<e.what()<<endl;
        cout<<"Test case 2 run tiume error"<<endl;
    }
    cout<<endl;

    try {
        cout<<"Test case 3: Insert left of root"<<endl;
        BST<int, int> st3;
        st3.insert(2, 2);
        st3.insert(1, 1);
    }
    catch (exception& e) {
        cout<<e.what()<<endl;
        cout<<"Test case 3 run tiume error"<<endl;
    }
    cout<<endl;

    try {
        cout<<"Test case 4: Insert right of root"<<endl;
        BST<int, int> st4;
        st4.insert(2, 2);
        st4.insert(5, 5);
    }
    catch (exception& e) {
        cout<<e.what()<<endl;
        cout<<"Test case 4 run tiume error"<<endl;
    }
    cout<<endl;

    try {
        cout<<"Test case 5: Insert negative number"<<endl;
        BST<int, int> st5;
        st5.insert(2, 2);
        st5.insert(-4, -4);
    }
    catch (exception& e) {
        cout<<e.what()<<endl;
        cout<<"Test case 5 run tiume error"<<endl;
    }
    cout<<endl;

    try {
        cout<<"Test case 6: Insert 0"<<endl;
        BST<int, int> st6;
        st6.insert(2, 2);
        st6.insert(0, 0);
    }
    catch (exception& e) {
        cout<<e.what()<<endl;
        cout<<"Test case 6 run tiume error"<<endl;
    }
    cout<<endl;


    return 0;
}