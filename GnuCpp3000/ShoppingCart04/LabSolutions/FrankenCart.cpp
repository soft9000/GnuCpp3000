#include "FrankenCart4.hpp"

using namespace Cart04;

FrankenCart::FrankenCart(ShoppingCart::UserData& user) : AbsUserCart(user) {}

float FrankenCart::getBalance() {
  float results = 0.0;
  for (list<Product>::iterator it = data.begin(); it != data.end(); ++it)
    results += it->price;
  results -= (results * (getDiscount() / 100.0));
  return results;
}

float FrankenCart::getDiscount() {
  if (this->user.isEmployee()) {
    return 10.0;
  }
  return 0.0;
}

bool FrankenCart::isAvailable(int item) {
  for (int ss = 0; ss < TOTAL_PRODUCTS; ss++) {
    if (item == Products[ss].id) {
      return true;
    }
  }
  return false;
}

int FrankenCart::addItem(int item) {
  if (isAvailable(item))
    data.push_back(Products[item]);
  return data.size();
}

int FrankenCart::removeItem(int item) {
  for (list<Product>::iterator it = data.begin(); it != data.end(); ++it) {
    if (item == it->id) {
      data.erase(it);
      return 1;
    }
  }
  return 0;
}

FrankenCart& FrankenCart::CreateCart(ShoppingCart::UserData& user) {
  return *(new FrankenCart(user));
}
