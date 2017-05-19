#include <iostream>

using std::cout;
using std::endl;

class Contained1 {
public:
    Contained1() {
      cout << "Contained1 constructor." << endl;
    }
};

class Contained2 {
public:
  Contained2() {
    cout << "Contained2 constructor." << endl;
  }
};

class Contained3 {
public:
  Contained3() {
    cout << "Contained3 costructor." << endl;
  }
};

class BaseContainer {
public:
  BaseContainer() {
    cout << "BaseContainer constructor" << endl;
  }
private:
  Contained1 c1;
  Contained2 c2;
};

class DerivedContainer: public BaseContainer {
public:
  DerivedContainer() : BaseContainer() {
    cout << "DerivedContainer constructor." << endl;
  }
private:
  Contained3 c3;
};

int main() {
  DerivedContainer dc;
  int x = 3;
}

/* OUTPUT
Contained1 constructor.
Contained2 constructor.
BaseContainer constructor
Contained3 costructor.
DerivedContainer constructor.
*/