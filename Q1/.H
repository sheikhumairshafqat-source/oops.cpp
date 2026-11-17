
#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

class DArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    DArray();
    DArray(const DArray& obj);
    ~DArray();

    void push_back(int value);

    DArray& operator=(const DArray& obj);

    friend ostream& operator<<(ostream& out, const DArray& obj);
};

#endif
