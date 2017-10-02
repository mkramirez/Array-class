#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

template <class T>
class Array {
public:
    Array(T size);
    ~Array();
    T & operator[](T i) const;
    T size() const;
    void fill(T k);
    T * begin();
    T * end();
    //int push(const T&);
    //int pop(T&);

private:
    T len;
    T * data;
};

template <class T>
Array<T>::Array(T size) {
    len = size;
    data = new T[len];
}

template <class T>
Array<T>::~Array(){
    delete [] data;
}

template <class T>
T &Array<T>::operator[](T i) const {
    return data [i];
}

template <class T>
T Array<T>::size() const {
    return len;
}

template <class T>
void Array<T>::fill(T k) {
    for(T i = 0; i < len; i++){
        data[i] = k;
    }
}

template <class T>
T *Array<T>::begin() {
    return & data[0];
}

template <class T>
T *Array<T>::end() {
    return & data[len];
}

int main(int argc, char * args[]) {
    Array <int> a(3);
    a[0] = 10;
    a[1] = 11;
    a[2] = 12;
    assert(a[0] == 10);
    assert(a[1] == 11);
    assert(a[2] == 12);
    assert(a.size() == 3);
    a.fill(5);
    assert(a[0] == 5);
    assert(a[1] == 5);
    assert(a[2] == 5);
    a[0] = 3;
    a[1] = 1;
    a[2] = 2;
    sort(a.begin(), a.end());
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 3);
    int * it = a.begin();
    assert(*it == 1);
    ++it;
    assert(*it == 2);
    ++it;
    assert(*it == 3);
    ++it;
    assert(it == a.end());
    cout << "All tests passed." << endl;
}