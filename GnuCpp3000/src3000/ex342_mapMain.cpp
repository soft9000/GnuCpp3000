#include "Products.hpp"
#include <algorithm>   // for_each
#include <functional>  // less<T>
#include <map>
#include <sstream>

using namespace std;

Product* mkProduct(int item_id) {
  stringstream srm;
  srm << "Simple ";
  srm << item_id;
  return new Product(item_id, srm.str(), 1.0 + (.10 * item_id));
}

void zPrint(const pair<int, Product>& pair) {
  cout << "f(" << pair.first << " == " << pair.second.id << ")" << endl;
}

int main(int argc, char* argv[]) {
  // ProductComparator is used to insure that set has "only one."
  map<int, Product, less<int>> data;

  // CREATE
  for (int ss = 0; ss < 10; ss++) {
    Product* ptr = mkProduct(ss);
    int id = ptr->id;
    data.insert(make_pair(id, *ptr));
  }

  // DELETE & UPDATE
  auto whence = data.begin();
  advance(whence, 5);
  Product* ptr = mkProduct(9000);
  int id = ptr->id;
  data.insert(make_pair(id, *ptr));
  data.erase(whence);

  // READ
  for (auto obj : data) {
    cout << obj.second.name << endl;
    cout << "\t" << obj.second.price;
    cout << "\t" << obj.first << endl;  // same as id.
  }

  // Using Iterators & Functors
  for_each(data.begin(), data.end(), zPrint);

  // cout << distance(data.begin(), data.end()) << endl;
  // cout << distance(data.end(), data.begin()) << endl;
}
