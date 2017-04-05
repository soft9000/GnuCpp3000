#include "AbsUserCart1.hpp"
#include "Common.hpp"
#include "Products.hpp"
#include <vector>

// DONE: Re-implement AbsUserCart signature using vetcor<Product>
namespace Cart03 {

class FrankenCart : public MyUserCart01::AbsUserCart {
 protected:
  vector<Product> data;
  virtual float getDiscount();

 public:
  FrankenCart(ShoppingCart::UserData& user);
  virtual float getBalance();
  virtual int addItem(int item);
  virtual int removeItem(int item);
  virtual bool isAvailable(int item);  // Check ID
  static FrankenCart& CreateCart(ShoppingCart::UserData& user);
};
}
