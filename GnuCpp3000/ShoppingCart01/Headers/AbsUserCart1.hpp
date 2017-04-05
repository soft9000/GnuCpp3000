#ifndef ACT320_ABSUSERCART01_HPP
#define ACT320_ABSUSERCART01_HPP
#include "UserData.hpp"

// AbsUserCart01:
// =============
// (o) Header based, as well as inline example
// (o) Object Factory not provided; protected
//     constructor will require child to create.

namespace MyUserCart01 {

class AbsUserCart {
 protected:
  int count = 0;
  int* items = new int[0];

  ShoppingCart::UserData& user;

  AbsUserCart(ShoppingCart::UserData& user) : user(user) {}

  virtual float getDiscount() = 0;

 public:
  virtual int addItem(int item) {
    int* pszArray = new int[count + 1];
    for (int ss = 0; ss < count; ss++)
      pszArray[ss] = items[ss];
    pszArray[count] = item;
    delete[] items;
    items = pszArray;
    return count++;
  }
};

}  // namespace ends

// Abstract... yet may still have an OPTIONAL implementation.
// Optional implementations can be re-used by child-classes (etc.))
// (inline usage NOT required - just saves us a file creation!))

inline float MyUserCart01::AbsUserCart::getDiscount() {
  if (this->user.isEmployee()) {
    return 10.0;
  }
  return 0.0;
}

#endif /* ACT320_ABSUSERCART01_HPP */
