#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

template <class T>
class Array {
public:
    Array(int size);
    ~Array();
    T & operator[](int i) const;
    int size() const;
    void fill(T k);
    T * begin();
    T * end();

private:
    int len;
    T * data;
};

template <class T>
Array<T>::Array(int size) {
    len = size;
    data = new T[len];
}

template <class T>
Array<T>::~Array(){
    delete [] data;
}

template <class T>
T &Array<T>::operator[](int i) const {
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
T *Array<T>::begin() {
    return & data[0];
}

template <class T>
T *Array<T>::end() {
    return & data[len];
}


class Animal {
public:
    virtual string speak() const = 0;
};

class Cat : public Animal {
public: 
    virtual string speak() const;
};

class Dog : public Animal {
public: 
    virtual string speak() const;
};

string Cat::speak() const {
	return "meow";
}

string Dog::speak() const {
	return "bark";
}


int main(int argc, char * args[]) {
	Array<Animal *> a(2);
	cout << a[1]->speak();  // Prints "meow" or "bark".

}
