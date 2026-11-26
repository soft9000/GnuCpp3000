#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char** argv) {
  vector<int> data;
  data.push_back(101);
  data.push_back(201);
  data.push_back(301);
  cout << "Stored: " << data.size() << endl;
  for (int ss = 0; ss < data.size(); ss++)
    cout << "Got: " << data[ss] << endl;
  data.pop_back();
  for (int ss = 0; ss < data.size(); ss++)
    cout << "Now: " << data[ss] << endl;
}
