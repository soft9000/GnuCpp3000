#include <iostream>

using namespace std;

namespace ex308 {

class IntObj {
 public:
  int value = 0;

  IntObj() {}

  IntObj(const IntObj& ref) : IntObj(ref.value) {}

  IntObj(int value) { this->value = value; }

  virtual IntObj& clone(const IntObj& ref) = 0;

  IntObj& operator=(const IntObj& num) {
    value = num.value;
    return *this;
  }
};

class BoolIntObj : public IntObj {
  bool bok = true;  // private
 public:
  virtual IntObj& clone(const IntObj& ref);
};
}

using namespace ex308;

IntObj& IntObj::clone(const IntObj& ref) {
  this->value = ref.value;
  return *this;
}

IntObj& BoolIntObj::clone(const IntObj& ref) {
  BoolIntObj* that = dynamic_cast<BoolIntObj*>((IntObj*)&ref);
  if (that != NULL) {
    std::puts("Casted");
    this->bok = that->bok;
  }
  return IntObj::clone(ref);
}

int main(int argc, char** argv) {
  BoolIntObj iobj;
  iobj.value = 123;
  BoolIntObj bobj;
  IntObj& result = bobj.clone(iobj);
  printf("Result %d\n", bobj.value);
  return 0;
}
