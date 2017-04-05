#include "AffiliateProduct.hpp"
namespace CompanyCart {

AProd::AProd(int prid, string name, float price, float discount)
    : discount(discount), Product(prid, name, price) {}

AProd::AProd(const AProd& ref) : Product(ref) {
  this->discount = ref.discount;
}

AProd::~AProd() {}

float AProd::price() {
  return special_price();
}

float AProd::special_price() {
  return (this->item_price * discount);
}

Product& AProd::operator=(const Product& ref) {
  Product::operator=(ref);
  const AProd* ap = dynamic_cast<const AProd*>(&ref);
  if (ap != nullptr) {
    this->discount = ap->discount;
  }
  return *this;
}
}
