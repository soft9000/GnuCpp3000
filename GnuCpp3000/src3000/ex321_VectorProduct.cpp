#include <iostream>
#include <vector>

class Product {};

using namespace std;
int main(int argc, char** argv) {
  Product d1, d2, d3;
  vector<Product> example;
  example.push_back(d1);
  example.push_back(d2);
  example.push_back(d3);
  cout << "Stored: " << example.size() << endl;
}
