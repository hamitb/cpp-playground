#include <iostream>

using std::cout;
using std::endl;

class base {
public:
  base() {}
  virtual ~base();
  void say_hi() {cout << "hi" << endl;}
};

base::~base() {cout << "base destructor called" << endl;}

class derived: public base {
public:
  derived() {}
  ~derived() {cout << "derived destructor called" << endl;}
  void say_hi() {cout << "hello" << endl;}  
};

int main() {
  base *aDerived = new derived;
  derived *bDerived = new derived;
  base *aBase = new base;

  aDerived->say_hi(); // hi
  bDerived->say_hi(); // hello
  aBase->say_hi(); // hi

  delete aDerived; // derived-base
  delete bDerived; // derived-base
  delete aBase; // base
}
