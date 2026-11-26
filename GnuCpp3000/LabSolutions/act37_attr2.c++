/*
g++ act37_attr2.c++ --std=c++14
g++ act37_attr2.c++ --std=c++11
*/
#include <iostream>
using namespace std;

[[deprecated("Whatever!")]] 
void meh(void) {
    cout << "Meh" << endl;
}

int main() {
    meh();
}
