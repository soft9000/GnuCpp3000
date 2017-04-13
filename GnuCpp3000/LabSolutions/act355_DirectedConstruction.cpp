#include <iostream>

using namespace std;

class class_top {
 public:
  int itop;
  class_top(int value) { this->itop = value; }
};

class class1 : virtual public class_top {
 public:
  class1() : class_top(1) {}
};

class class2 : virtual public class_top {
 public:
  class2() : class_top(2) {}
};

class ClassBottom : public class1, public class2 {
 public:
  ClassBottom() : class_top(99) {}
};

int main(void) {
  ClassBottom* gem = new ClassBottom();
  cout << "Got: " << gem->itop << endl;
  delete gem;
}
