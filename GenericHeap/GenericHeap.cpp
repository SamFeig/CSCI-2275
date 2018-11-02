
#include <iostream>;
using namespace std;


template <typename T>
class GenericHeap {
private:
    int *heap;
    int capacity = 0;
    int currentSize = 0;

public:
    GenericHeap(int size) {
        capacity = size;
        heap = new int[capacity];
        for(int i = 0; i < capacity; i++) {
            heap[i] = -1;
        }
    }
    void push(T k) {
        if(currentSize == capacity) {
            heap = resize(currentSize);
        }
//        else {
            currentSize++;
            int i = currentSize;
            heap[i] = k;

            while(i > 1 & heap[i/2] > heap[i]) {
                swap(heap[i/2], heap[i]);
                i = i/2;
            }
//        }
    }

    int pop() { //remove the root
        if(currentSize == 0) {
            //Heap is empty
            return -1;
        }
        if(currentSize == 1) {
            currentSize--;
            return heap[1];
        }
        if(capacity / 2 = currentSize) {
           heap = resize(currentSize);
        }
        int popVal = heap[1];
        heap[1] = heap[currentSize];
        currentSize--;
        minHeapify(1);
        return popVal;
    }

    void minHeapify(int i) {
        int left = 2*i;
        int right = 2*i+1;
        int smallest = i;

        if(left <= currentSize & heap[left] < heap[smallest]) {
            smallest = left;
        }
        if(right <= currentSize & heap[right] < heap[smallest]) {
            smallest = right;
        }
        if(smallest != i) {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }

    void maxHeapify(int i) {
        int left = 2*i;
        int right = 2*i+1;
        int largest = i;

        if(left <= currentSize & heap[left] > heap[largest]) {
            largest = left;
        }
        if(right <= currentSize & heap[right] > heap[largest]) {
            largest = right;
        }
        if(largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

    void heapSort() {//int arr[], int n
        // One by one extract an element from heap
        for(int i = currentSize; i > 0; i--) {
            // Move current root to end
            swap(heap[1], heap[i]);
            // call max heapify on the reduced heap
            minHeapify(i);
        }
    }

    int* resize(int number) {
        if(capacity == currentSize) {
            cout<<"Doubling Array"<<endl;
            capacity = capacity * 2;
        }
        else {
            cout<<"Halving Array"<<endl;
            capacity = capacity / 2;
        }
        int *tmp = new int(capacity);
        for(int i = 1; i <= number; i++) {
            tmp[0] = -1;
            tmp[i] = heap[i];
        }
        delete [] heap;
        return tmp;
    }

    void printArray() {
        for(int i = 1; i <= currentSize; i++) {
            cout << heap[i] << " ";
        }
        cout << "\n";
    }

};