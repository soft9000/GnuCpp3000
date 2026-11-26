/*
g++ act35_attr.c++ --std=c++14
g++ act35_attr.c++ --std=c++11
*/
#include <iostream>
using namespace std;

[[deprecated]] 
void meh(void) {
    cout << "Meh" << endl;
}

int main() {
    meh();
}

