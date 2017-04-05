#include "Products.hpp"

Product::Product(int product_id, string name, float price) {
  this->id = product_id;
  this->name.assign(name);
  this->price = price;
}

Product Products[] = {Product(1, "Widget 21", 122.43),
                      Product(2, "Widget 22", 212.00),
                      Product(3, "Widget 23", 354.42)};
