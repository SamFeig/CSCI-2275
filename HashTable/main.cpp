#include <iostream>
#include <cmath>
using namespace std;

int hash2(string , int);

int main() {
    string strings[] = {"Benjamin", "John", "Cameron", "Bob", "Andrew", "Matt", "Kylie"};

    int size = sizeof(strings)/sizeof(strings[0]);

    for(string s : strings) {
       int hash = hash2(s, size);
        cout<<s<<" : "<<hash<<endl;
    }
    return 0;
}

int hash2(string s, int size) {
    int R = 256;
    int Q = 1315423911; //large prime

    long hash = 0;
    for (int i = 0; i < size; i++)
        hash = R * hash + s[i];// % Q;

    return (hash % size);
}
