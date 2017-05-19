#include <iostream>
using std::cout;
using std::endl;

class BaseClass {
public:
  BaseClass() {
    print_it();
  }
  virtual void print_it() {
    cout << "BaseClass print_it" << endl;
  }
};

class DerivedClass: public BaseClass {
public:
  DerivedClass() {
    print_it();
  }
  void print_it(){
    cout << "Derived Class print_it" << endl;
  }
};

void func(BaseClass* obj) {
  obj->print_it();
}

int main() {
  DerivedClass* dc = new DerivedClass();
  func(dc);
}

/* OUTPUT
BaseClass print_it
Derived Class print_it
Derived Class print_it
*/
