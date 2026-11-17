
#include "DArray.h"

DArray::DArray() {
    arr = nullptr;
    s = 0;
    cap = 0;
}

DArray::DArray(const DArray& obj) {
    s = obj.s;
    cap = obj.cap;

    if (cap == 0)
        arr = nullptr;
    else
        arr = new int[cap];

    for (int i = 0; i < s; i++) {
        arr[i] = obj.arr[i];
    }
}

DArray::~DArray() {
    delete[] arr;
}

void DArray::push_back(int value) {

    if (s == cap) {

        if (cap == 0)
            cap = 1;
        else
            cap = cap * 2;

        int* temp = new int[cap];

        for (int i = 0; i < s; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

    arr[s] = value;
    s++;
}

int DArray::size() const {
    return s;
}

int DArray::capacity() const {
    return cap;
}

int& DArray::operator[](int index) {
    return arr[index];
}

DArray& DArray::operator=(const DArray& obj) {

    if (this != &obj) {

        delete[] arr;

        s = obj.s;
        cap = obj.cap;

        if (cap == 0)
            arr = nullptr;
        else
            arr = new int[cap];

        for (int i = 0; i < s; i++) {
            arr[i] = obj.arr[i];
        }
    }

    return *this;
}

ostream& operator<<(ostream& out, const DArray& obj) {

    for (int i = 0; i < obj.s; i++) {
        out << obj.arr[i] << " ";
    }

    return out;
}
