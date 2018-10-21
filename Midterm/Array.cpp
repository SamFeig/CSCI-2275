#include "Array.h"
#include <iostream>

using namespace std;
Array::Array(int initVal, int size)
{
    arrayData = new int[size];
    arraySize = size;
    /*We know that when we declare an array, we
    get a block of uninitialized memory. It's a good
    idea to initialize the array values in the constructor
    so that we know we don't have garbage.*/
    for(int i = 0; i < arraySize; i++){
        arrayData[i] = initVal;
    }
}

Array::~Array()
{
    //dtor
    arraySize = 0;
    delete [] arrayData;
}
/*This method loops through every used index in the array
and prints the value in the array.
*/
void Array::printData(){
    for(int i = 0; i < currentIndex; i++)
        cout<<arrayData[i]<<endl;
}

/*Add a new value to the array at the currentIndex
position. This operation succeeds if the array
isn't full. Otherwise, print array full.*/
void Array::appendData(int value){
    if(currentIndex < arraySize){
        arrayData[currentIndex] = value;
        currentIndex++;
    }else{
        cout<<"array full"<<endl;
    }
}
/*Insert a value at a specified index. Every other
value is shifted out of the way to make room for the
new value.*/
void Array::insertData(int value, int index){
    //check if it's a valid index and there is room in the array
    if((index < arraySize) && (currentIndex < arraySize - 1)){
        //insert a new value at the beginning of the array. Shift everything out of the way
        //shift from the end to the beginning
        for(int x = currentIndex; x > index; x--){
            arrayData[x] = arrayData[x-1];
        }
        arrayData[index] = value; //new value at index
        currentIndex++; //the number of used spaces is increased by 1

    }else{
        cout<<"array full or invalid index"<<endl;
    }
}

/*delete a value in an array at a specified index. Every
other value in the array is shifted to fill the space
occupied by the deleted element.

We don't actually have to delete it, we just need to overwrite
the value we no longer want. We can do this by shifting all
values to the right of the value down by 1 to
overwrite it.
*/
void Array::deleteData(int index){
    for(int x = index; x < currentIndex-1; x++){
        arrayData[x] = arrayData[x+1];
    }
    currentIndex--;
}

void Array::printAboveValue(int value) {
    int num = 0;
    for(int i = 0; i < currentIndex; i++) {
        if(arrayData[i] > value) {
            cout << arrayData[i] << endl;
            num++;
        }
    }
    if(num == 0) {
        cout<<"No values found"<<endl;
    }
}