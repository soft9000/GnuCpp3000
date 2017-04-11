#include <iostream>

using namespace std;

void dump_bits(char bits) {
  for (int op = 0; op < 8; op++) {
    unsigned ptrn = (bits << op);
    int mask = ptrn & 0x80;
    int comp = !mask;
    cout << !comp;
  }
  cout << endl;
}

int main(void) {
  dump_bits(0xF0);
  dump_bits(0x0F);
  dump_bits(0xA0);
  dump_bits(0xAA);
  dump_bits(0xFF);
  dump_bits(0x00);
  return 0;
}
