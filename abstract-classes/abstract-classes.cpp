#include <iostream>

using std::cout;
using std::endl;

// Base class
class Shape {
public:
  // pure virtual function providing interface freamwork
  virtual int getArea() = 0;

  void setWidth(int w) {
    width = w;
  }
  
  void setHeight(int h) {
    height = h;
  }
protected:
  int width;
  int height;
};

// Derived classes
class Triangle: public Shape {
public:
  int getArea() {
    return (width * height)/2;
  }
};

class Rectangle: public Shape {
public:
  int getArea() {
    return (width * height);
  }
};

int main() {
  Rectangle Rect;
  Triangle Tri;

  Rect.setWidth(5);
  Rect.setHeight(7);

  cout << "Total rectangle area: " << Rect.getArea() << endl;

  Tri.setWidth(5);
  Tri.setHeight(7);

  cout << "Total Triangle area: " << Tri.getArea() << endl;

  return 0;
}
