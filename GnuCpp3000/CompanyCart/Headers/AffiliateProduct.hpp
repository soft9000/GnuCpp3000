#ifndef AffiliateProduct
#define AffiliateProduct

#include "Product.hpp"

namespace CompanyCart {

class AProd : public Product {
 private:
  float discount = 0.0;

 public:
  AProd(int product_id, string name, float price, float discount);
  AProd(const AProd& copy);
  virtual ~AProd();
  virtual float price();  // 2nd virtual implied, technically not required
  float special_price();
  virtual Product& operator=(const Product& ref);
};
}

#endif /* AffiliateProduct */
