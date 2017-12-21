#ifndef ACT321_MYUSERCART02_HPP
#define ACT321_MYUSERCART02_HPP

#include "AbsUserCart1.hpp"
#include <cstring>

namespace Cart02 {

using namespace MyUserCart01;

// Use of negatives allows co-existence with integral array-ops

enum TROOL { opOk = -1, opIgnored = -2, opError = -9 };

class FrankenCart : public AbsUserCart {
 public:
  // Friendship allows access to private constructor

  FrankenCart(ShoppingCart::UserData& user) : AbsUserCart(user) {}

  int nelem() { return count; }

  // Convert to new TROOL result

  int addItem(int item) {
    // Is actually AbsUserCart ...
    if (AbsUserCart::addItem(item) < 0)
      return TROOL::opError;
    return TROOL::opOk;
  }

  // Using new TROOL result

  int subtractItem(int item) {
    int tot = 0;
    int* pszArray = new int[count];
    for (int xx = 0; xx < count; xx++)
      if (items[xx] == item)
        continue;
      else
        pszArray[tot++] = items[xx];

    if (tot != 0) {
      delete[] items;
      items = new int[tot];
      memcpy(items, pszArray, tot * sizeof(int));
    }
    delete [] pszArray; // Prevent "Memory Leak"
    count = tot;
    return TROOL::opOk;
  }

  int operator+=(int item) { return addItem(item); }

  int operator-=(int item) { return subtractItem(item); }

  // Moved to header - from the previous FrankenCart:
  float getDiscount() { return AbsUserCart::getDiscount(); }

  FrankenCart& CreateCart(ShoppingCart::UserData& user) {
    return *(new FrankenCart(user));
  }
};

}  // namespace

#endif /* ACT321_MYUSERCART02_HPP */
