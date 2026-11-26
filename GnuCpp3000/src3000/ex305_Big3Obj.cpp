#include <iostream>

using namespace std;

class IntObj {
 public:
  int value = 0;

  IntObj() {}

  IntObj(const IntObj& ref) : IntObj(ref.value) {}

  IntObj(int value) { this->value = value; }

  IntObj& operator=(const IntObj& num) {
    value = num.value;
    return *this;
  }
};

class BoolIntObj : public IntObj {
  bool bok = true;

 public:
  BoolIntObj(bool bok = false, int value = 221) : IntObj(value) {
    this->bok = bok;
  }
};

int main(int argc, char** argv) {
  puts("ex305");
  // "on the stack"
  IntObj obj1(123);
  IntObj obj2(321);
  obj1 = obj2;
  printf("Assigned: %d\n", obj1.value);
  // "in global memory"
  IntObj& robj1 = *(new IntObj(101));
  IntObj* pobj2 = new IntObj(10);
  printf("Assigned: %d\n", (robj1 = *pobj2).value);
  // Related
  BoolIntObj bo;
  printf("BoolIntObj: %d\n", bo.value);

  return 0;
}
