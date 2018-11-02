#include "terrible_dynamic_size_array_unsorted.h"

using namespace std;


void init(int_array& arr)
{
	arr.count = 0;
	arr.capacity = arr.DEFAULT_CAPACITY;
	arr.data = new int[arr.capacity];
}

void clear(int_array& arr)
{
	destr(arr);
	init(arr);
}

void destr(int_array& arr)
{
	delete [] arr.data;
	arr.count = 0;
}

void print(const int_array& arr)
{
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
	cout << endl;
}

bool contains(const int_array& arr, const int& target)
{
	unsigned int i;
	
	for (i = 0; i < arr.count; ++i) //Removed ;
	{
		if (arr.data[i] == target) return true;
//		else return false;	//Removed, returned false prematurely
	}
	return false;
}

void resize(int_array& arr)
{
	arr.capacity *= 2;
	int* new_data = new int[arr.capacity];
	for (unsigned int i = 0; i < arr.count; i++) //changed ++i to i++
	{
		new_data[i] = arr.data[i];
	}

    delete [] new_data; //remove darr.data changed to new_data
	arr.data = new_data;
	
}

void add(int_array& arr, const int& payload)
{
	
	if ((arr.count == arr.capacity))
		resize(arr);
	
	
	arr.data[arr.count++] = payload; //Changed ++arr.count to arr.count++
	
}

bool remove(int_array& arr, const int& target)
{
	unsigned int i = 0;


	if (arr.count == 0) //Changed = to ==
		return false;

	while (i < arr.count && arr.data[i] != target) i++;

	if (i == arr.count)
		return false;

	arr.data[i] = arr.data[arr.count];//

	arr.count--;
	return true;


//    int i = 0;
//    for(i = 0; i < arr.count && arr.data[i] != target; i++) {
//        arr.data[i] = arr.data[i+1];
//    }
//    if(i == arr.capacity) {
//        return false;
//    }

}

