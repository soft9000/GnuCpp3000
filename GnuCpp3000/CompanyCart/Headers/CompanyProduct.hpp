#ifndef CompanyProduct
#define CompanyProduct

#include "Product.hpp"

namespace CompanyCart {

class CProd : public Product {
 public:
  CProd(int product_id, string name, float price)
      : Product(product_id, name, price) {}
  CProd(const Product& copy);
  virtual ~CProd();

  float price();
};
}

#endif /* CompanyProduct */
