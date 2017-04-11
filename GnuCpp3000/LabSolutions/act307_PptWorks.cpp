#include <cstdio>

using namespace std;

namespace lcycle {
using namespace std;
class Thing {
 public:
  Thing() { puts("Thing"); }
  ~Thing() { puts("~Thing"); }
};
class Place : public Thing {
 public:
  Place() { puts("Place"); }
  ~Place() { puts("~Place"); }
};
class Person : public Place {
 public:
  Person() { puts("Person"); }
  ~Person() { puts("~Person"); }
};
}

namespace vlcycle {
using namespace std;
class Thing {
 public:
  Thing() { puts("Thing"); }
  virtual ~Thing() { puts("~Thing"); }
};
class Place : public Thing {
 public:
  Place() { puts("Place"); }
  virtual ~Place() { puts("~Place"); }
};
class Person : public Place {
 public:
  Person() { puts("Person"); }
  virtual ~Person() { puts("~Person"); }
};
}

int main(int argc, char** argv) {
  {
    puts("Creating Person");
    lcycle::Thing* person = new lcycle::Person();
    puts("Un-Creating Person");
    delete person;
  }
  puts("Creating vPerson");
  vlcycle::Thing* person = new vlcycle::Person();
  puts("Un-Creating vPerson");
  delete person;
  return 0;
}
