#ifndef ARRAY_H
#define ARRAY_H

class Array
{
    public:
        Array(int, int);
        ~Array();
        void printData();
        void appendData(int);
        void deleteData(int);
        void insertData(int, int);
        void printAboveValue(int);
    protected:
    private:
        int *arrayData;
        int arraySize;
        int currentIndex = 0;
};

#endif // ARRAY_H
