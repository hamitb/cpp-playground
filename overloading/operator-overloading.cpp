#include <iostream>

using std::cout;
using std::endl;

class Box {
public:
  double getVolume() {
    return length * breadth * height;
  }

  void setLength(double len) {
    length = len;
  }

  void setBreadth(double bre) {
    breadth = bre;
  }

  void setHeight(double hei) {
    height = hei;
  }

  // Overloaded + operator
  Box operator+(const Box& b) {
    Box box;
    box.length = this->length + b.length;
    box.breadth = this->breadth + b.breadth;
    box.height = this->height + b.height;
    return box;
  }

private:
  double length;
  double breadth;
  double height;
};

int main() {
  Box Box1;
  Box Box2;
  Box Box3;
  double volume = 0.0;

  Box1.setLength(6.0);
  Box1.setBreadth(6.0);
  Box1.setHeight(6.0);

  Box2.setLength(12.0);
  Box2.setBreadth(12.0);
  Box2.setHeight(6.0);

  volume = Box1.getVolume();
  cout << "Volume of Box1: " << volume << endl;

  volume = Box2.getVolume();
  cout << "Volume of Box2: " << volume << endl;

  Box3 = Box1 + Box2;

  volume = Box3.getVolume();
  cout << "Volume of Box3: " << volume << endl;

  return 0;
}

/* OUTPUT
Volume of Box1: 216
Volume of Box2: 864
Volume of Box3: 3888
*/
