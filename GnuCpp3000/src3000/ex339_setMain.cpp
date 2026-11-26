#include "Products.hpp"
#include <functional>  // less<T>
#include <set>
#include <sstream>

using namespace std;

Product* mkProduct(int item_id) {
  stringstream srm;
  srm << "Simple ";
  srm << item_id;
  return new Product(item_id, srm.str(), 1.0 + (.10 * item_id));
}

struct ProductComparator {
  ProductComparator(){};
  // The "Functor" Construct:
  bool operator()(Product ref1, Product ref2) {
    cout << "f()" << endl;
    return (ref1.id != ref2.id);
  }
};

int main(int argc, char* argv[]) {
  // ProductComparator is used to insure that set has "only one."
  set<Product, ProductComparator> data;

  // CREATE
  for (int ss = 0; ss < 10; ss++) {
    Product* ptr = mkProduct(ss);
    data.insert(*ptr);
    data.insert(*ptr);  // set<T> IGNORES redundancies!
  }

  // DELETE & UPDATE
  set<Product>::iterator whence = data.begin();
  advance(whence, 5);
  data.insert(*mkProduct(9000));
  data.erase(whence);

  // READ
  for (auto obj : data) {
    cout << obj.name << endl;
    cout << "\t" << obj.price;
    cout << "\t" << obj.id << endl;
  }

  // cout << distance(data.begin(), data.end()) << endl;
  // cout << distance(data.end(), data.begin()) << endl;
}
