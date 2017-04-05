#include "CompanyProduct.hpp"

namespace CompanyCart {

CProd::CProd(const Product& copy) : Product(copy) {}

CProd::~CProd() {}

float CProd::price() {
  return this->item_price;
}
}
