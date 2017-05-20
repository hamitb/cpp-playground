#include <iostream>

using std::cout;
using std::endl;

class base {
public:
  base() {}
  virtual ~base()=0;
};

base::~base() {}

class derived: public base {
public:
  derived() {}
  ~derived() {}
};

int main() {
  derived *pDerived = new derived;
  delete pDerived;
}
