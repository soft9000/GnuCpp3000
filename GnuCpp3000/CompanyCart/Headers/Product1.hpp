#ifndef PRODUCT_HPP1
#define PRODUCT_HPP1

#include "Common.hpp"

namespace CompanyCart {

class Product {
 protected:
  int id = -1;
  float item_price = 0.0;
  string name;

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
};
}

#endif /* PRODUCT_HPP1 */
