#include "Products.hpp"
#include <list>
#include <sstream>

Product* mkProduct(int item_id) {
  stringstream srm;
  srm << "Simple ";
  srm << item_id;
  return new Product(item_id, srm.str(), 1.0 + (.10 * item_id));
}

int main(int argc, char* argv[]) {
  list<Product> data;

  // CREATE
  for (int ss = 0; ss < 10; ss++)
    data.push_back(*mkProduct(ss));

  // DELETE & UPDATE
  for (list<Product>::iterator it = data.begin(); it != data.end(); it++) {
    if (it->id == 5) {
      data.emplace(it, *mkProduct(9000));
      data.erase(it);
      break;
    }
  }

  // READ
  for (Product obj : data) {
    cout << obj.name << endl;
    cout << "\t" << obj.price;
    cout << "\t" << obj.id << endl;
  }
}
