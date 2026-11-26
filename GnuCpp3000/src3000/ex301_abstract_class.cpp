#include <iostream>

namespace ex301 {

class AbsUserCart {
 private:
  int count = 0;
  int* items = NULL;

 protected:
  virtual float getDiscount(int count, int* items) = 0;

 public:
  float getBalance() { return getDiscount(count, items); }
  // ... item management (CRUD) assumed ...
};

class userPublic : public AbsUserCart {
 protected:
  virtual float getDiscount(int count, int* items) { return 0.0f; }
};

enum User_T { aPublic, aEmployee };

AbsUserCart& Create(User_T user) {
  switch (user) {
    case aPublic:
      return *(new userPublic);
    case aEmployee:
      return *(new userPublic);
  }
}
}

int main(int argc, char* argv[]) {}
