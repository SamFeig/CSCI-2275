#include <iostream>
#include "terrible_dynamic_size_array_unsorted.cpp"

int main() {
    //Test cases go here

    int_array arr;
    init(arr);

    add(arr, 5);
    int a = 6;
    add(arr, a);
    add(arr, 7);
    add(arr, 8);

    print(arr);
    cout<< contains(arr, 6)<<endl;
    resize(arr);
    print(arr);

    remove(arr, 6);
    print(arr);




    return 0;
}