/* No Virtual - Simply Overriding parental definitions.
*/
#include <iostream>

using namespace std;

namespace BlogNouns {

enum Types { typeThing, typePlace, typePerson };

// Simplified

class Thing {
 public:
  void speak(const char* psz = "Ima Thing") { printf("Thing: %s\n", psz); }

  static Thing& Create(Types which);
};

class Place : public Thing {
 public:
  void speak(const char* psz = "Ima Place") { printf("Place: %s\n", psz); }
};

class Person : public Place {
 public:
  void speak(const char* psz = "Ima Person") { printf("Person: %s\n", psz); }
};

Thing& Thing::Create(Types which) {
  switch (which) {
    case typeThing:
      return *(new Thing);
    case typePerson:
      return *(new Person);
    case typePlace:
      return *(new Place);
  }
}
}

using namespace BlogNouns;

int main(int argc, char** argv) {
  {
    puts("MyNouns");
    Thing& noun = Thing::Create(Types::typePerson);
    noun.speak();
    delete &noun;

    noun = Thing::Create(Types::typePlace);
    noun.speak();
    delete &noun;

    noun = Thing::Create(Types::typeThing);
    noun.speak();
    delete &noun;
  }
  puts("BlogNouns");
  Person& person = (Person&)Thing::Create(Types::typePerson);
  person.speak();
  delete &person;

  Place& place = (Place&)Thing::Create(Types::typePlace);
  place.speak();
  delete &place;

  Thing& thing = Thing::Create(Types::typeThing);
  thing.speak();
  delete &thing;

  return 0;
}
