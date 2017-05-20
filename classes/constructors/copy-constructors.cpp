#include <iostream>

using std::cout;
using std::endl;

class Line {
public:
  int getLength();
  Line(int len); //simple const
  Line(const Line& obj); //copy const
  ~Line(); //dest
private:
  int *ptr;
};

Line::Line(int len) {
  cout << "Normal constructor allocating ptr" << endl;

  //allocate memory for the pointer
  ptr = new int;
  *ptr = len;
}

Line::Line(const Line &obj) {
  cout << "Copy constructor allocating ptr." << endl;
  ptr = new int;
  *ptr = *obj.ptr; // copy the value
}

Line::~Line() {
  cout << "Freeing memory!" << endl;
}

int Line::getLength() {
  return *ptr;
}

void display(Line obj) {
  cout << "Length of line: " << obj.getLength() << endl;
}

int main() {
  Line line1(10);

  Line line2 = line1; 
  
  display(line1); //This also calls copy constructor 

  return 0;
}
