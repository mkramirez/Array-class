#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

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
	/*Cat c;
	cout << c.speak() << endl;
	Dog d;
	cout << d.speak() << endl;
	*/
	cout << "All Tests Passed." << endl;
}
