#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char** argv) {
  vector<int> data;
  for (int ss = 0; ss < 3; ss++) {
    data.push_back(1000 + ss);
  }
  vector<int>::iterator it;
  it = find(data.begin(), data.end(), 1001);
  data.erase(it);  // .remove() will not .erase()
  data.insert(data.end(), 9000);
  data.insert(data.begin(), -1);
  for (int ss = 0; ss < data.size(); ss++)
    cout << "Got: " << data[ss] << endl;
}
