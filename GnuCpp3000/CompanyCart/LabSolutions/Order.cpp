#include "Order.hpp"
#include "AffiliateProduct.hpp"
#include "CompanyProduct.hpp"
#include <cassert>  // R&D

namespace CompanyCart {

vector<Product*> Order::read() {
  vector<Product*> results;
  for (auto it = data.begin(); it != data.end(); ++it) {
    Product* item = NULL;
    CProd* cp = dynamic_cast<CProd*>(*it);
    if (cp != nullptr)
      item = new CProd(*cp);
    else {
      AProd* ap = dynamic_cast<AProd*>(*it);
      assert(ap != nullptr);  // TODO: Exception
      item = new AProd(*ap);
    }
    assert(item != NULL);  // TODO: Exception
    item->origin = (*it);
    results.push_back(item);
  }
  return results;
}

bool Order::add(Product* bought) {
  if (bought == NULL)
    return false;
  data.push_back(bought);
  return true;
}

bool Order::update(Product* bought) {
  if (bought == NULL)
    return false;
  if (bought->origin == NULL)
    return add(bought);
  bought->origin->operator=(*bought);
  return true;
}

void Order::remove(Product* bought) {
  if (bought != NULL) {
    if (bought->origin != NULL) {
      for (auto it = data.begin(); it != data.end(); ++it) {
        Product* row = (Product*)(*it);
        if (bought->item_id() == row->item_id()) {
          data.erase(it);
          bought->origin = NULL;
          return;
        }
      }
    }
  }
}
}
