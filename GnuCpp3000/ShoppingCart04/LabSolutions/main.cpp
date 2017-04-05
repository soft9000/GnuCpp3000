#include "FrankenCart4.hpp"
#include <cassert>

/*
Objectives here are to:
(1) Implements AbsUserCart using a list<T>
(2) Use the "New Requirement"
(3) Test same.
 */

using namespace Cart04;

int main(int argc, char* argv[]) {
  ShoppingCart::UserData user;
  user.setName("Master Joe");
  user.setEmail("MasterJoe@MyMail27.com");
  FrankenCart& cart = FrankenCart::CreateCart(user);
  for (int ss = 0; ss < TOTAL_PRODUCTS; ss++)
    cart.addItem(Products[ss].id);

  cout.precision(7);
  cout << "isEmployee ";
  cout << user.isEmployee() << ": $";
  cout << cart.getBalance() << endl;

  user.setEmail("MasterJoe@soft9000.com");
  cout << "isEmployee ";
  cout << user.isEmployee() << ": $";
  cout << cart.getBalance() << endl;

  cout << "Emptying cart ..." << endl;
  for (int ss = 0; ss < TOTAL_PRODUCTS; ss++)
    cart.removeItem(Products[ss].id);
  cout << cart.getBalance() << endl;
}
