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
  list<Product>::iterator whence = data.begin();
  advance(whence, 5);
  data.insert(whence, *mkProduct(9000));
  data.erase(whence);

  // READ
  for (auto obj : data) {
    cout << obj.name << endl;
    cout << "\t" << obj.price;
    cout << "\t" << obj.id << endl;
  }

  cout << distance(data.begin(), data.end()) << endl;
  cout << distance(data.end(), data.begin()) << endl;
}
