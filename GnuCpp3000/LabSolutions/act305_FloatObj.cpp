#include <iostream>
#include <cstdio>

using namespace std;

namespace act305 {

class FloatObj {
 public:
  float value = 0.0f;

  FloatObj() {}

  FloatObj(const FloatObj& ref) : FloatObj(ref.value) {}

  FloatObj(int value) { this->value = value; }

  FloatObj& operator=(const FloatObj& num) {
    value = num.value;
    return *this;
  }
};

class FloatObj2 : public FloatObj {
 public:
  FloatObj2() : FloatObj() {}
  
  FloatObj2(const FloatObj2& ref) : FloatObj((FloatObj&)ref) {}

  FloatObj2(float value = 221) : FloatObj(value) {}

  FloatObj2& operator=(const FloatObj2& num) {
    FloatObj::operator=((FloatObj&)num);
    return *this;
  }

  FloatObj2& operator=(const FloatObj& num) {
    FloatObj::operator=((FloatObj&)num);
    return *this;
  }
};
}

using namespace act305;

int main(int argc, char** argv) {
  puts("act305");
  FloatObj2 child(100);
  FloatObj parent(200);
  child = parent;
  printf("Child is: %.02f\n", child.value);
  child.value = 123.0f;
  parent = child;
  printf("Parent now: %.02f\n", parent.value);

  // Test Copy Constructor
  FloatObj2 copy(child);
  if (copy.value != child.value)
    cerr << "Error\n";
  else
    cout << "Success\n";

  return 0;
}

