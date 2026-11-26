#include <iostream>

using namespace std;

void dump_bits(char bits) {
  for (int op = 0; op < 8; op++) {
    unsigned ptrn = (bits << op);  // shift bits left
    int mask = ptrn & 0x80;        // see high-order
    int comp = !mask;              // 1,1,1,1,0,0,0,0
    cout << !comp;                 // 0,0,0,0,1,1,1,1
  }
  cout << endl;
}

int main(void) {
  dump_bits(0xF0);
  return 0;
}
