#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

template <class T>
class Array {
    T values [3]; //Number can be fixed to whatever you want.

public:
    Array(T first, string second, double third){
        values[0] = first;
        values[1] = second;
        values[2] = third;
    }
};

class testSpam {
public:
    testSpam(int * helper1, string * helper2, double * helper3);
    ~testSpam();
    //void fill(int j, string k, double l);
    //int helper1();
    //string helper2();
    //double helper3();
    /*int 아 = 1;
    string 애 = "안녕";
    double 야 = 0.2; */
private:
    int * spam1;
    string * spam2;
    double * spam3;
};

testSpam::testSpam(int *helper1, string *helper2, double *helper3) {
    spam1 = helper1;
    spam2 = helper2;
    spam3 = helper3;
}

testSpam::~testSpam() {
    delete [] spam1, spam2, spam3;
}


int main(int argc, char * args[]) {


}