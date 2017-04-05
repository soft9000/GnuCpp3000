#include "FrankenCart1.hpp"

FrankenCart::FrankenCart(ShoppingCart::UserData& user) : AbsUserCart(user) {}

float FrankenCart::getDiscount() {
  return MyUserCart01::AbsUserCart::getDiscount();
}

FrankenCart& FrankenCart::CreateCart(ShoppingCart::UserData& user) {
  return *(new FrankenCart(user));
}
