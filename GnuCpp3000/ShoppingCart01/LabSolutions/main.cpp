#include "FrankenCart1.hpp"

// Idea here is to re-use a definition for an abstract virtual function.
using namespace MyUserCart01;

// NOTE: Returning non-zero generates `make` error.
int main(void) {
  ShoppingCart::UserData user;
  user.setName("Master Joe");
  user.setEmail("MasterJoe@MyMail27.com");
  {
    FrankenCart& cart = FrankenCart::CreateCart(user);
    for (int ss = 0; ss < 10; ss++)
      cart.addItem(10);

    if (cart.getDiscount() != 0) {
      cerr << "Error: Employee Discount" << endl;
      return -1;
    }
  }
  user.setName("Master Joe");
  user.setEmail("MasterJoe@soft9000.com");
  FrankenCart& cart = FrankenCart::CreateCart(user);
  if (cart.getDiscount() == 0) {
    cerr << "Error: No Employee Discount" << endl;
    return -1;
  }

  cout << "Success." << endl;
  return 0;
}
