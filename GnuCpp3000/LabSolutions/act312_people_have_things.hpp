#define MAX_THINGS 5

class Thing final {
 protected:
  int id = -1;

 public:
  Thing(int which);
};

class People {
 private:
  Thing* array[MAX_THINGS];

 public:
  People();
  bool add(Thing* thing);
};
