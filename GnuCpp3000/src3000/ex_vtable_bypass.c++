/*
g++ ex_vtable_bypass.c++ --std=c++11
*/
#include <iostream>

class Parent {
public:
    virtual void print() {
        std::cout << "Hello from Parent!\n";
    }
};

class Child : public Parent {
public:
    void print() override {
        // 1. Call parent function (No virtual dispatch)
        Parent::print(); 
        
        // 2. Local specialized logic
        std::cout << "Hello from Child!\n"; 
    }
};

int main() {
    Child c;
    c.print(); 
    return 0;
}

