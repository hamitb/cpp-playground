#include <iostream>
using std::cout;
using std::endl;

// Base class Shape
class Shape {
public:
  void setWidth(int w) {
    width = w;
  }

  void setHeight(int h) {
    height = h;
  }

  virtual void shapeType() {
    cout << "Generic shape" << endl;
  }

  protected:
    int width;
    int height;
};

// Base class PaintCost
class PaintCost {
public:
  int getCost(int area) {
    return area * 70;
  }
};

// Derived class
class Rectangle: public Shape, public PaintCost {
public:
  int getArea() {
    return (width * height);
  }

  void shapeType() {
    cout << "It's a rectangle" << endl;    
  }
};

void printType(Shape* shape) {
  shape->shapeType();
}

class Square: public Shape, public PaintCost {
public:
  void shapeType() {
    cout << "It's a square" << endl;
  }
};

int main() {
  Rectangle* Rect = new Rectangle();
  Square* sq = new Square();
  Shape* generic = new Shape();
  int area;

  Rect->setWidth(5);
  Rect->setHeight(7);

  area = Rect->getArea();

  cout << "Total area: " << Rect->getArea() << endl;

  cout << "Total paint cost : $" << Rect->getCost(area) << endl;

  printType(Rect);
  printType(sq);
  printType(generic);


  return 0;
}

/* OUTPUT
Total area: 35
Total paint cost : $2450
*/
