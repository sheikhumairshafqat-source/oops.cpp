#include<iostream>
#include "DArray.h"
using namespace std;

DArray::DArray() {
    arr = nullptr;
    size = 0;
    capacity = 0;
}

DArray::DArray(const DArray& obj) {
    size = obj.size;
    capacity =obj.capacity;

    arr =new int[capacity];

    for (int i =0; i< size;i++) {
        arr[i] =obj.arr[i];
    }
}

DArray::~DArray() {
    delete[] arr;
}

void DArray::push_back(int value) {

    if (size == capacity) {

        if (capacity ==0)
            capacity =1;
        else
            capacity = capacity * 2;

        int* temp =new int[capacity];

        for (int i =0; i< size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

    arr[size] = value;
    size++;
}

DArray& DArray::operator=(const DArray& obj) {

    if (this != &obj) {

        delete[] arr;

        size = obj.size;
        capacity = obj.capacity;

        arr = new int[capacity];

        for (int i = 0; i < size; i++) {
            arr[i] = obj.arr[i];
        }
    }

    return *this;
}

ostream& operator<<(ostream& out, const DArray& obj) {

    for (int i = 0; i < obj.size; i++) {
        out << obj.arr[i] << " ";
    }

    return out;
}
