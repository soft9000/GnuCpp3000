//#include "era.hpp"
//using namespace era01;


#include <iostream> // cerr
using namespace std;

void execptional() {
  throw "Just Exceptional";
}

// As presented in Session 1000:
int previous_main(int argc, char* argv[]) {
  try {
    execptional();
  } catch (const char *ex) {
    cout << "Error: " << ex << endl;
    return 1; // Non-Zero: "error"
  }
  return 0; // "okay"
}

#include <exception> // base class
using namespace std;

struct FauxException : public exception {
   const char *c_str() const throw () {
      return "Test Exception";
   }
};
 
int main(void) {
   try {
      throw FauxException();
   }catch(FauxException& e) {
      cout << "FauxException: ";
      cout << e.c_str() << endl;
   } catch(exception& e) {
      // Others may be thrown, as well!
   }
}
