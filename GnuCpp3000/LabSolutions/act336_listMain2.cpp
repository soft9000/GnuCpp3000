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

// Called until TRUE is returned...
bool Goal(const Product& prod) {
  return (prod.id == 5000);
}

int main(int argc, char* argv[]) {
  list<Product> data;

  // CREATE
  for (int ss = 0; ss < 10; ss++)
    data.push_back(*mkProduct(ss));

  // READ
  for (auto obj : data) {
    cout << obj.name << endl;
    cout << "\t" << obj.price;
    cout << "\t" << obj.id << endl;
  }

  // SEARCH
  list<Product>::iterator found = find_if(data.begin(), data.end(), Goal);
  while (found != data.end()) {
    cout << found->name << endl;
    found = next(found);
  }
}
