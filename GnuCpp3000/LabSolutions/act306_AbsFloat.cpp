#include <iostream>

using namespace std;

namespace act306 {

class AbsFloat {
 public:
  virtual AbsFloat& clone(AbsFloat& ref) = 0;
};

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

  virtual AbsFloat& clone(AbsFloat& ref) {
    this->value = ((FloatObj&)(ref)).value;
    return (AbsFloat&)*this;
  }
};

class FloatObj2 : public FloatObj {
 public:
  FloatObj2() : FloatObj() {}

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

using namespace act306;

int main(int argc, char** argv) {
  puts("act306");
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

  // Test Clone Operation
  parent.clone((AbsFloat&)child);
  if (parent.value != child.value)
    cerr << "Error\n";
  else
    cout << "Success\n";

  return 0;
}
