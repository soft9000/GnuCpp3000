#include <iostream>  // unloved

class class_top {
 public:
  int itop;
};

class class1 : virtual public class_top {};

class class2 : virtual public class_top {};

class ClassBottom : public class1, public class2 {
 public:
  int ibot;
};

int main(void) {
  ClassBottom* gem = new ClassBottom();
  int foo = gem->ibot;
  int bar = gem->itop;
  delete gem;
}
