#include "AffiliateProduct.hpp"
#include "CompanyProduct.hpp"
#include "Order.hpp"
#include <cassert>
#include <sstream>

using namespace CompanyCart;

void show(vector<Product*> copy) {
  int ss = 1;
  for (auto ref = copy.begin(); ref != copy.end(); ref++) {
    Product* item = (*ref);
    cout << ss++ << ".) " << item->description();
    cout << " @ " << item->price() << endl;
  }
}

void free(vector<Product*> copy) {
  for (auto ref = copy.begin(); ref != copy.end(); ref++) {
    Product* item = (*ref);
    delete item;
  }
}

void banner(const char* msg) {
  cout << endl << endl;
  cout << "::::: " << msg << " :::::";
  cout << endl;
}

int main(void) {
  Order order;

  banner("Test Data");
  for (int ss = 1; ss < 4; ss++) {
    int num = 100 + ss;
    stringstream srm;
    srm << "CompanyProduct ";
    srm << num;
    assert(order.add(new CProd(num, srm.str(), 10.01 * ss)) == true);
    num = 1000 + ss;
    srm = stringstream();
    srm << "AffiliateProduct " << num;
    assert(order.add(new AProd(num, srm.str(), (12.34 * ss), 0.75)) == true);
  }

  vector<Product*> copy = order.read();

  assert(copy.size() == 6);
  show(copy);

  banner("Access");
  Product* item = copy[3];
  cout << item->description() << " @ " << item->price() << endl;
  assert(item->price() == 18.51F);

  banner("Removal");
  order.remove(item);
  order.remove(item);
  free(copy);

  copy = order.read();
  assert(copy.size() == 5);
  show(copy);

  banner("Update");
  item = copy[3];
  (*item) = "UPDATED";
  (*item) = 123.456F;
  order.update(item);
  free(copy);

  copy = order.read();
  assert(copy.size() == 5);
  item = copy[3];
  assert(item->description() == "UPDATED");
  assert(item->price() == 123.456F);
  show(copy);
  free(copy);

  banner("Testing Success");
}
