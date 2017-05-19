#include <iostream>

using std::cout;
using std::endl;

class Line {
  public:
    void setLength(double len);
    double getLength();
    Line(double len);

  private:
   double length;
};

Line::Line(double len) {
  cout << "Object is  being crated with length: " << len << endl;
  length = len;
}

void Line::setLength(double len) {
  length = len;
}

double Line::getLength() {
  return length;
}

//Main function for the program
int main() {
  Line line(10.0);

  cout << "Length of line: " << line.getLength() << endl;

  return 0;
}
