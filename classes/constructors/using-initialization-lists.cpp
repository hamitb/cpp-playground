#include <iostream>

using std::cout;
using std::endl;

class Box {
public:
  Box(){ cout<<"default called"<<endl, m_height = 1, m_length = 1, m_width = 1; }
  Box(int width, int length, int height)
    : m_width(width), m_length(length), m_height(height) // member init list
  { cout<<"parameterized called"<<endl; }

  int Volume() { return m_width * m_length * m_height; }
private:
  int m_height;
  int m_length;
  int m_width;
};

int main() {
  Box b1(2, 3, 5);
  Box b2; // Calles default constructor
  Box boxes[3]; // Calles default constructor for each object

  cout << "The volume is " << b1.Volume() << endl;
  cout << "The volume is " << b2.Volume() << endl;
  cout << "The volume is " << boxes[0].Volume() << endl;

  return 0;
}

/* OUTPUT
parameterized called
default called
default called
default called
default called
The volume is 30
The volume is 1
The volume is 1
*/
