#include "Products.hpp"
#include <algorithm>
#include <list>
#include <sstream>

Product* mkProduct(int item_id) {
  stringstream srm;
  srm << "Simple ";
  srm << item_id;
  return new Product(item_id, srm.str(), 1.0 + (.10 * item_id));
}

struct PComp {
  bool operator()(const Product& left, const Product& right) {
    return left.price > right.price;
  }
};

int main(int argc, char* argv[]) {
  list<Product> data;

  // CREATE
  for (int ss = 0; ss < 10; ss++)
    data.push_back(*mkProduct(ss));

  // SORT
  // data.sort(PComp()); // ()'s are REQUIRED!
  // LAMBDA-SORT
  data.sort([](const Product& left, const Product& right) {
    return left.price > right.price;
  });

  // READ
  for (auto obj : data) {
    cout << obj.name << endl;
    cout << "\t" << obj.price;
    cout << "\t" << obj.id << endl;
  }
}
