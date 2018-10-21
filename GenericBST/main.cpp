#include <iostream>
#include "RecitationBST.cpp"
#include "BST.cpp"
using namespace std;

int main() {
    BST<int, int> st;
    st.insert(2, 2);
    st.insert(7, 7);
    st.insert(4, 4);
    st.insert(6, 6);
    cout<<st.get(2)<<endl;
    st.insert(1, 1);
    st.printInorder();
    cout<<endl;
    st.levelOrderTraversal();


    return 0;
}