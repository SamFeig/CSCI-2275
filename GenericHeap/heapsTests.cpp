#include <iostream>
#include <exception>

using namespace std;

void heapPush(int *heap, int value, int capacity, int *cSize){
	if (*cSize == capacity){
		cout<<"heap full"<<endl;
	}
//	if(value == 0) {
//        cout<<"value of 0 entered"<<endl;
//    }
//    if(value < 0) {
//        cout<<"neg value entered"<<endl;
//    }
	else{
		*cSize = *cSize + 1;
		int i = *cSize;
		heap[*cSize] = value;
		cout<<heap[*cSize]<<endl;
		while(i > 1 and heap[i/2] > heap[i]){
			int temp = heap[i/2];
			heap[i/2] = heap[i];
			heap[i] = temp;
			i = i / 2;
		}

	}
}
void minHeapify(int *heap, int *currentSize, int i){
	int left = 2*i;
	int right = 2*i + 1;
	int smallest = i;
	if (left <= *currentSize and heap[left] < heap[i]){
		smallest = left;
	}
	if(right <= *currentSize and heap[right] < heap[smallest]){
		smallest = right;
	}
	if(smallest != i){
		int temp = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = temp;
		minHeapify(heap, currentSize, smallest);
	}
}

int heapPop(int *heap, int capacity, int *cSize){
	int popVal;
	if (*cSize == 0){
		cout<<"empty"<<endl;
		return -1;
	}
	if(*cSize == 1){
		*cSize = *cSize - 1;
		return heap[1];
		
	}else{
		popVal = heap[1];
		heap[1] = heap[*cSize];
		*cSize = *cSize - 1;
		minHeapify(heap, cSize, 1);
	}
	return popVal;

}
int main(){
	int capacity = 5;
	int *currentSize = new int;
	*currentSize = 0;
//	int *heap = new int(capacity);
//	for(int i = 0; i < capacity; i++){
//		heap[i] = 0;
//	}
//	heapPush(heap, 10, capacity, currentSize);
//	heapPush(heap, 20, capacity, currentSize);
//	heapPush(heap, 1, capacity, currentSize);
//	heapPush(heap, 5, capacity, currentSize);
//	heapPush(heap, 15, capacity, currentSize);
//
//
//	for(int i = 0; i <= *currentSize; i++){
//		cout<<heap[i]<<endl;
//	}
//	int returnValue;
//	returnValue = heapPop(heap, capacity, currentSize);
//	cout<<returnValue<<endl;

    cout<<"Test Push"<<endl;
	try {
        cout<<"max capacity"<<endl;
        *currentSize = 0;
        int *heap = new int[capacity];
        for(int i = 0; i < capacity; i++){
            heap[i] = 0;
        }
        heapPush(heap, 10, capacity, currentSize);
	    heapPush(heap, 20, capacity, currentSize);
        heapPush(heap, 1, capacity, currentSize);
	    heapPush(heap, 5, capacity, currentSize);
	    heapPush(heap, 15, capacity, currentSize);
        heapPush(heap, 12, capacity, currentSize);
	}
	catch(exception& e ) {
	    cout<<e.what()<<endl;
	}
    try {
        cout<<"neg number"<<endl;
        *currentSize = 0;
        int *heap2 = new int[capacity];
        for(int i = 0; i < capacity; i++){
            heap2[i] = 0;
        }
        heapPush(heap2, 10, capacity, currentSize);
        heapPush(heap2, 20, capacity, currentSize);
        heapPush(heap2, -6, capacity, currentSize);
        heapPush(heap2, 15, capacity, currentSize);
    }
    catch(exception& e ) {
        cout<<e.what()<<endl;
    }
    try {
        cout<<"zero"<<endl;
        *currentSize = 0;
        int *heap3 = new int[capacity];
        for(int i = 0; i < capacity; i++){
            heap3[i] = 0;
        }
        heapPush(heap3, 10, capacity, currentSize);
        heapPush(heap3, 20, capacity, currentSize);
        heapPush(heap3, 0, capacity, currentSize);
        heapPush(heap3, 5, capacity, currentSize);
        heapPush(heap3, 15, capacity, currentSize);
    }
    catch(exception& e ) {
        cout<<e.what()<<endl;
    }
    try {
        cout<<"duplicate number"<<endl;
        *currentSize = 0;
        int *heap4 = new int[capacity];
        for(int i = 0; i < capacity; i++){
            heap4[i] = 0;
        }
        heapPush(heap4, 10, capacity, currentSize);
        heapPush(heap4, 20, capacity, currentSize);
        heapPush(heap4, 10, capacity, currentSize);
        heapPush(heap4, 5, capacity, currentSize);
        heapPush(heap4, 15, capacity, currentSize);
    }
    catch(exception& e ) {
        cout<<e.what()<<endl;
    }

    try {
        cout<<"neg capacity"<<endl;
        capacity = 10;
        *currentSize = 0;
        int *heap5 = new int(capacity);
        int *heap = new int[15];
        for(int i = 0; i < 15; i++){
            heap[i] = 999;
        }
        heapPush(heap5, 10, capacity, currentSize);
        heapPush(heap5, 20, capacity, currentSize);
        heapPush(heap5, 1, capacity, currentSize);
        heapPush(heap5, 5, capacity, currentSize);
        heapPush(heap5, 15, capacity, currentSize);
        heapPush(heap5, 15, capacity, currentSize);
        heapPush(heap5, 15, capacity, currentSize);
        heapPush(heap5, 15, capacity, currentSize);
        heapPush(heap5, 15, capacity, currentSize);
        heapPush(heap5, 15, capacity, currentSize);

//        for(int i = 0; i <= *currentSize; i++){
		cout<<endl<<endl<<heap5[16]<<endl;
//	}
    }
    catch(exception& e ) {
        cout<<"Error in cap"<<endl;
        cout<<e.what()<<endl;
    }



	return 0;	
}
