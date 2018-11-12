#include <iostream>
#include <string>
using namespace std;

struct MovieNodeH {
    int ranking;
    std::string title;
    int year;
    int quantity;

    MovieNodeH(){
        quantity = 0;
        year = 0;
        title = "";
        ranking = 0;
    }

    MovieNodeH(int in_ranking, string in_title, int in_year, int in_quantity) {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
    }

//    MovieNodeH& operator=(const MovieNodeH& right) {
//        (*this).ranking = right.ranking;
//        (*this).title = right.title;
//        (*this).year = right.year;
//        (*this).quantity = right.quantity;
//    }
};

bool operator<(const MovieNodeH& left, const MovieNodeH& right) {
    return left.quantity < right.quantity;
}
bool operator>(const MovieNodeH& left, const MovieNodeH& right) {
    return left.quantity > right.quantity;
}
bool operator==(const MovieNodeH& left, const MovieNodeH& right) {
    return left.quantity == right.quantity;
}

class Heap {
private:
    MovieNodeH *heap;
    int capacity = 0;
    int currentSize = 0;
    MovieNodeH* m;
    int removedIndex = 0;

public:
    Heap() {
        capacity = 10;
        heap = new MovieNodeH[capacity];
    }
    Heap(int size) {
        capacity = size;
        heap = new MovieNodeH[capacity];
    }
    ~Heap() {
        cout<<"Deleting "<<heap[1].title[0] <<" heap" <<endl;
        delete[] heap;
    }
    void push(int ranking, string title, int releaseYear, int quantity) {
        if(currentSize == capacity) {
//            heap = resize(currentSize);
            cout<<"Full!!"<<endl;
            return;
        }
//        else {
        currentSize++;
        int i = currentSize;
//        heap[i] = k;
//        copy(heap[i], k);
        heap[i].quantity = quantity;
        heap[i].title = title;
        heap[i].year = releaseYear;
        heap[i].ranking = ranking;

        while(i > 1 & heap[i/2] < heap[i]) {
            MovieNodeH* tmp = new MovieNodeH();
            copy(*tmp, heap[i]);
            copy(heap[i], heap[i/2]);
            copy(heap[i/2], *tmp);
            delete tmp;
//            swap(heap[i/2], heap[i]);
            i = i/2;
        }
//        }
    }

    MovieNodeH pop() { //remove the root
        if(currentSize == 0) {
            //Heap is empty
            cout<<'Heap Full'<<endl;
            return MovieNodeH();
        }
        if(currentSize == 1) {
            currentSize--;
            return heap[1];
        }

        MovieNodeH popVal = heap[1];
//        cout<<popVal.title<<endl;
//        cout<<heap[1].title <<" "<<heap[currentSize].title <<endl;
        copy(heap[1], heap[currentSize]);
//        cout<<heap[1].title <<" "<<heap[currentSize].title <<endl;
        currentSize--;
//        cout<<heap[1].title <<" "<<heap[currentSize].title <<endl;
        maxHeapify(1);


//        int root = harr[0];
//        harr[0] = harr[heap_size-1];
//        heap_size--;
//        MinHeapify(0);
        return popVal;
    }

    void copy(MovieNodeH& a, MovieNodeH& b) {
        if(&b == nullptr) {
            a.quantity = 0;
            a.title = "";
            a.year = 0;
            a.ranking = 0;
        }
        else {
            a.quantity = b.quantity;
            a.title = b.title;
            a.year = b.year;
            a.ranking = b.ranking;
        }
    }

    int size() {
        return currentSize;
    }

    void decSize() {
        currentSize--;
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
            MovieNodeH* tmp = new MovieNodeH();
            copy(*tmp, heap[i]);
            copy(heap[i], heap[largest]);
            copy(heap[largest], *tmp);
            delete tmp;
//            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

    void printArray() {
        for(int i = 1; i <= currentSize; i++) {
            cout << heap[i].title <<": " <<heap[i].quantity << ", ";
        }
        cout<<endl<<endl;
    }

    void printTop10Array() {
        removedIndex = 0;
        m = new MovieNodeH[10];
        for(int i = 0; i < 11; i++) {
            m[i].quantity = 0;
            m[i].year = 0;
            m[i].title = "";
            m[i].ranking = 0;
        }
        int minVal = min(10, currentSize);

        for(int i = 0; i < minVal; i++) {
            m[removedIndex] = pop();
            cout << m[removedIndex].title << ": " << m[removedIndex].quantity << ", ";
            removedIndex++;
        }
        cout<<endl<<endl;

//        cout<<"Popped:"<<endl;
//        for(int i = 0; i < removedIndex; i++) {
//            cout<<m[i].title<<endl<<endl;
//        }
    }

    void reAddTop10() {
        if(m != nullptr) {
            for(int i = 0; i < 10; i++) {
                if(m[i].title != "") {
//                    cout<<"Pushing " <<m[i].title <<endl;
                    push(m[i].ranking, m[i].title, m[i].year, m[i].quantity);
                    m[i] = MovieNodeH();
                    removedIndex--;
                }
            }
        }
    }

    MovieNodeH* search(string s) {
        int i = 1;
        while(i <= currentSize) {
           if(heap[i].title.compare(s) != 0) {
               i++;
           }
           else {
               return &heap[i];
           }
        }
        return nullptr;
    }
};
