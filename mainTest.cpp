#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

template <class T>
class Array {
public:
    Array(T size);
    ~Array();
    int & operator[](T i) const;
    int size() const;
    void fill(T k);
    int * begin();
    int * end();
    //int push(const T&);
    //int pop(T&);

private:
    T len;
    T * data;
};

template <class T>
Array<T>::Array(T size) {
    len = size;
    data = new int[len];
}

template <class T>
Array<T>::~Array(){
    delete [] data;
}

template <class T>
int &Array<T>::operator[](T i) const {
    return data [i];
}

template <class T>
int Array<T>::size() const {
    return len;
}

template <class T>
void Array<T>::fill(T k) {
    for(T i = 0; i < len; i++){
        data[i] = k;
    }
}

template <class T>
int *Array<T>::begin() {
    return & data[0];
}

template <class T>
int *Array<T>::end() {
    return & data[len];
}

int main(int argc, char * args[]) {
    Array <int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 3);

    cout << "All tests passed." << endl;
    return 0;
}