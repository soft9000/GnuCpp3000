#include "act312_people_have_things.hpp"
#include <cassert>
#include <iostream>

using namespace std;

Thing::Thing(int which) {
  this->id = which;
}

People::People() {
  for (int ss = 0; ss < MAX_THINGS; ss++)
    array[ss] = NULL;
}

bool People::add(Thing* thing) {
  for (int ss = 0; ss < MAX_THINGS; ss++) {
    if (array[ss] == NULL) {
      array[ss] = thing;
      return true;
    }
  }
  return false;
}

int main(int argc, char** argv) {
  People person;
  for (int ss = 0; ss < MAX_THINGS * 2; ss++) {
    if (person.add(new Thing(ss)) == false) {
      assert(ss == MAX_THINGS);
      cout << "Testing Success " << ss << endl;
      return (int)true;
    }
  }
  cerr << "Testing Error" << endl;
  return (int)false;
}
