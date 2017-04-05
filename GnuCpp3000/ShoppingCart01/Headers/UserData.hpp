#ifndef USERDATA_HPP
#define USERDATA_HPP

#include "Common.hpp"

namespace ShoppingCart {

class UserData {
 protected:
  string name;
  string email;
  float accountBalance = 0.0;

 public:
  void setName(string str);
  void setEmail(string str);
  void setBalance(float bal);
  bool isEmployee();
};
}

#endif /* USERDATA_HPP */
