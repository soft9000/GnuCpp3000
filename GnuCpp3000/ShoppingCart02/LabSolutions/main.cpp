#include "FrankenCart2.hpp"
#include <cassert>

/*
Idea here is to:
 (1) Re-use ShoppingCart01 / FrankenCart
 (2) Use enum TROOL
 (3) Introduce Operator Overloading
 */
using namespace Cart02;

int main(int argc, char* argv[]) {
  ShoppingCart::UserData user;
  user.setName("Master Joe");
  user.setEmail("MasterJoe@soft9000.com");
  FrankenCart cart(user);
  for (int ss = 0; ss < 10; ss++)
    if (cart.addItem(ss) != TROOL::opOk) {
      cout << "Error: addItem()" << endl;
      return -1;
    }

  assert(cart.nelem() == 10);

  cout.precision(7);
  cout << "isEmployee ";
  cout << user.isEmployee() << endl;

  user.setEmail("MasterJoe@MyMail27.com");
  cout << "isEmployee ";
  cout << user.isEmployee() << endl;

  assert(cart.nelem() == 10);
  cout << "Emptying..." << endl;
  for (int ss = 0; ss < 10; ss++) {
    int result = (cart -= (ss));
    if (result != TROOL::opOk) {
      cout << "Error: operator::-=()" << endl;
      return -1;
    }
  }
  assert(cart.nelem() == 0);

  for (int ss = 0; ss < 10; ss++)
    if ((cart += (10)) != TROOL::opOk) {
      cout << "Error: addItem()" << endl;
      return -1;
    }

  assert(cart.nelem() == 10);
  cout << "Success - All is well!" << endl;
}
