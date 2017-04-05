#ifndef FRANKEN_CART_HPP
#define FRANKEN_CART_HPP
#include "AbsUserCart1.hpp"

// Note: FrankenCart is NOT part of the MyUserCart01 Namespace!

class FrankenCart : public MyUserCart01::AbsUserCart {
 private:
  // DONE: Re-using protected constructor (private okay due to Factory))
  FrankenCart(ShoppingCart::UserData& user);

 public:
  // DONE: Re-using the "Optional" implementation for an abstract member.
  float getDiscount();

  // DONE: Created static member "Factory"
  static FrankenCart& CreateCart(ShoppingCart::UserData& user);
};

#endif
