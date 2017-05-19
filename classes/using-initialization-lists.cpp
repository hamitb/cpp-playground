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

Line::Line(double len): length(len) {
  cout << "Object is  being crated with length: " << len << endl;
}

void Line::setLength(double len) {
  length = len;
}

double Line::getLength() {
  return length;
}

//Main function for the program
int main() {
  Line line(7.0);

  cout << "Length of line: " << line.getLength() << endl;

  return 0;
}
