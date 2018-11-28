#include <iostream>
using namespace std;

int hash2(string, int);

int main() {
    string strings[] = {"Sam", "John", "Carl", "Bob", "Kylie", "Tim", "Alex"};

    int size = sizeof(strings)/sizeof(strings[0]);

    for(string s : strings) {
        cout<<hash2(s, size)<<endl;
    }
    return 0;
}

int hash2(string s, int size) {
    switch(s[0]) {
        case "A":

            break;
    }
}