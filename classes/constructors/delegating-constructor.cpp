#include <iostream>
using std::cout;
using std::endl;

class ConstructorDestructor {
public:
  ConstructorDestructor() {
    cout << "Default constructor" << endl;
  }
  ConstructorDestructor(int int1) {
    cout << "Constructor with 1 int" << endl;
  }
  ConstructorDestructor(int int1, int int2): ConstructorDestructor(int1) {
    cout << "Constructor with 2 ints" << endl;
  }
  ConstructorDestructor(int int1, int int2, int int3): ConstructorDestructor(int1, int2) {
    cout << "Constructor with 3 ints" << endl;
  }
  ~ConstructorDestructor() {
    cout << "ConstructorDestructor destructor" << endl;
  }
};

int main() {
  ConstructorDestructor dc(1, 2, 3);
}
