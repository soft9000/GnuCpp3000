#include <iostream>
#include <vector>

class product {};

class company_product : public product {};

class affiliate_product : public product {};

using namespace std;
int main(int argc, char** argv) {
  vector<product> example;
  example.push_back(*(new product()));
  example.push_back(*(new company_product()));
  example.push_back(*(new affiliate_product()));
  cout << "Stored: " << example.size() << endl;
}
