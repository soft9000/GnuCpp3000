#include "Common.hpp"
#include "Product.hpp"
#include <vector>

namespace CompanyCart {

class Order {
 private:
  vector<Product*> data;

 public:
  virtual vector<Product*> read();
  virtual bool add(Product* bought);
  virtual bool update(Product* bought);
  virtual void remove(Product* bought);
};
}
