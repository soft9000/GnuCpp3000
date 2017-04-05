#include "Product.hpp"

namespace CompanyCart {

Product::Product(int product_id, string zname, float zprice) {
  this->id = product_id;
  this->name = zname;
  this->item_price = zprice;
}

Product::Product(const Product& copy) {
  (*this) = copy;
}

Product::~Product() {}

float Product::price() {
  return this->item_price;
}

int Product::item_id() {
  return this->id;
}

string Product::description() {
  return this->name;
}

Product& Product::operator=(const Product& copy) {
  this->id = copy.id;
  this->name = copy.name;
  this->item_price = copy.item_price;
  this->origin = copy.origin;
  return *this;
}
}
