#include <iostream>
using namespace std;

class SameSig {
 public:
  void show(int i) { cout << "as int: " << i << endl; }

  void show(double f) { cout << "as double: " << f << endl; }

  void show(const char* c) { cout << "as char: " << c << endl; }
};

int main(void) {
  SameSig pd;
  pd.show(55);
  pd.show(654.321);
  pd.show("C++");
  return 0;
}
