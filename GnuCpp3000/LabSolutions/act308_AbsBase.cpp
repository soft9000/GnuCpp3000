// c++  -std=c++11 act308*

#include <iostream>

namespace act308 {

class AbsBase {
 public:
  int value = 0;

  AbsBase() {}

  AbsBase(const AbsBase& ref) : AbsBase(ref.value) {}

  AbsBase(int value) { this->value = value; }

  virtual AbsBase& clone(const AbsBase& ref) = 0;
};

class Base : public AbsBase {
 public:
  std::__cxx11::string name;
  virtual AbsBase& clone(const AbsBase& ref);
};
}

using namespace std;
using namespace act308;

AbsBase& AbsBase::clone(const AbsBase& ref) {
  this->value = ref.value;
  return *this;
}

AbsBase& Base::clone(const AbsBase& ref) {
  Base* that = dynamic_cast<Base*>((AbsBase*)&ref);
  if (that != NULL) {
    std::puts("Casted");
    this->name.assign(that->name.c_str());
  }
  return AbsBase::clone(ref);
}

int main(int argc, char** argv) {
  Base iobj;
  iobj.value = 123;
  iobj.name.assign("Rex");
  Base bobj;
  AbsBase& result = bobj.clone(iobj);
  Base& base = static_cast<Base&>(result);
  printf("Result Name: %s, Value: %d\n", base.name.c_str(), base.value);
  return 0;
}
