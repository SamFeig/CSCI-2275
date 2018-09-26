#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int* doubleArray(int array[], int& size, int number);

int main(int argc, char *argv[]) {
    int size = 10;
    int *ptr = new int[size];

    ifstream myfile(argv[1]);
    string line;
    int num = 0;
    while(getline(myfile,line)) {
        ptr[num] = stoi(line);
        num++;
        if(num == size) {
            ptr = doubleArray(ptr, size, num);
        }
    }
    myfile.close();

    for(int i = 0; i < num; i++) {
        cout<<ptr[i]<<endl;
    }
    return 0;
}

int* doubleArray(int array[], int& size, int number) {
    size = size * 2;
    int *tmp = new int[size];
    for(int i = 0; i < number; i++) {
        tmp[i] = array[i];
    }
    delete [] array;
    return tmp;
}