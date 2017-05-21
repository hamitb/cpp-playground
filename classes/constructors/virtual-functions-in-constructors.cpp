#include <iostream>
using std::cout;
using std::endl;

class BaseClass {
public:
  BaseClass() {
  }
  virtual void print_it() {
    cout << "BaseClass print_it" << endl;
  }
};

class DerivedClass: public BaseClass {
public:
  DerivedClass() {
  }
  void print_it(){
    cout << "Derived Class print_it" << endl;
  }
};

class DerivedClass2: public BaseClass {
public:
  DerivedClass2() {
  }
};

void func(BaseClass* obj) {
  obj->print_it();
}

int main() {
  DerivedClass* dc = new DerivedClass();
  DerivedClass2* dc2 = new DerivedClass2();
  
  func(dc);
  func(dc2);
}

/* OUTPUT
BaseClass print_it
Derived Class print_it
Derived Class print_it
*/
