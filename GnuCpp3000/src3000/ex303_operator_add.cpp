#include <iostream>

namespace ex303 {

class absAccount {
 private:
  int count = 0;
  int* items = NULL;

 protected:
  virtual float getDiscount(int count, int* items) = 0;

 public:
  float getBalance() { return getDiscount(count, items); }

  int addItem(int item) {
    int* pszArray = new int[count + 1];
    for (int ss = 0; ss < count; ss++)
      pszArray[ss] = items[ss];
    pszArray[count] = item;
    delete items;
    items = pszArray;
    return count++;
  }

  int operator+=(int item) { return addItem(item); }
};

class userPublic : public absAccount {
 protected:
  virtual float getDiscount(int count, int* items) { return 0.0f; }
};

enum User_T { aPublic, aEmployee };

absAccount& Create(User_T user) {
  switch (user) {
    case aPublic:
      return *(new userPublic);
    case aEmployee:
      return *(new userPublic);
  }
}
}

using namespace ex303;

int main(int argc, char** argv) {
  absAccount& pub = ex303::Create(User_T::aPublic);
  printf("added item: %d\n", pub.addItem(102));
  printf("added item: %d\n", pub += 127);
  printf("discount: %f", pub.getBalance());
  delete &pub;
}
