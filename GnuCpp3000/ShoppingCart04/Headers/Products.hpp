#ifndef PRODUCTS_HPP
#define PRODUCTS_HPP

#include "Common.hpp"

struct Product {
  int id = -1;
  float price = 0.0;
  string name;

  Product(int product_id, string name, float price);
};

#define TOTAL_PRODUCTS 3

extern Product Products[];

#endif /* PRODUCTS_HPP */
