#include <iostream>
using std::cout;
using std::endl;

class BaseClass1 {
public:
  BaseClass1(int x): x(x) {
    cout << "BaseClass1 constructor" << endl;
  }
protected:
  int x;
};

class BaseClass2 {
public:
  BaseClass2(int y): y(y) {
    cout << "BaseClass2 constructor" << endl;
  }
protected:
  int y;
};

class BaseClass3 {
public:
  BaseClass3(int z): z(z) {
    cout << "BaseClass3 constructor" << endl;
  }
protected:
  int z;
};

class DerivedClass: public BaseClass1, public BaseClass2, public BaseClass3 {
public:
  DerivedClass(int x, int y, int z): BaseClass1(x), BaseClass2(y), BaseClass3(z) {
    cout << "DerivedClass constructor" << endl;
  }
  void printParameters() {
    cout << x << ", " << y << ", " << z << endl;
  }
};

int main() {
  DerivedClass dc(1,2,3);
  dc.printParameters();
}

/* OUTPUT
BaseClass1 constructor
BaseClass2 constructor
BaseClass3 constructor
DerivedClass constructor
1, 2, 3
*/

