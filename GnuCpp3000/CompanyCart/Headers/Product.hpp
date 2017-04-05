#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "Common.hpp"

namespace CompanyCart {

class Product {
 protected:
  int id = -1;
  float item_price = 0.0;
  string name;
  // Pair-up copy
  Product* origin = NULL;

 public:
  Product(int product_id, string name, float price);
  Product(const Product& copy);
  virtual ~Product();
  int item_id();
  string description();
  virtual float price() = 0;
  virtual Product& operator=(const Product& copy);

  Product& operator=(const char* desc) {
    this->name = string(desc);
    return *this;
  }

  Product& operator=(float iprice) {
    this->item_price = iprice;
    return *this;
  }

  friend class Order;
};
}

#endif /* PRODUCT_HPP */
