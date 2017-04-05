#include "../Headers/UserData.hpp"

using namespace ShoppingCart;

void UserData::setName(string str) {
  this->name.assign(str);
}

void UserData::setEmail(string str) {
  this->email.assign(str);
}

void UserData::setBalance(float bal) {
  this->accountBalance = bal;
}

bool UserData::isEmployee() {
  return (email.find("soft9000.com") != string::npos);
}
