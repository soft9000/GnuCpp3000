#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int main(int argc, char** argv) {
  list<int> data = {11, 21, 31};
  for (int obj : data) {
    cout << obj << endl;
  }
}
