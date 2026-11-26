#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char** argv) {
  vector<int> data;
  for (int ss = 0; ss < 3; ss++) {
    data.push_back(1000 + ss);
  }
  vector<int>::iterator pos = data.begin();
  data.insert(pos, -1);
  pos = data.end();
  data.insert(pos, 9000);
  for (int ss = 0; ss < data.size(); ss++)
    cout << "Got: " << data[ss] << endl;
}
