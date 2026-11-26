#include <iostream>

class[[deprecated]] Oldie{};

[[deprecated("Operation upgraded!")]] int steam_power() {
  std::cout << "ops..." << std::endl;
  return 0;
}

int main() {
  Oldie f;
  return steam_power();
}
