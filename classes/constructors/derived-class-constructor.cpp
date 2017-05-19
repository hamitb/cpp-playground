#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Box {
public:
  Box(int width, int length, int height)
    : m_width(width), m_length(length), m_height(height) // member init list
  { cout<<"base constructor called"<<endl; }
private:
  int m_height;
  int m_length;
  int m_width;
};

class StorageBox: public Box {
public:
  StorageBox(int width, int length, int height, const string &label): Box(width, length, height) {
      cout << "derived constructor called" << endl;
      m_label = label;
    }
private:
  string m_label;
};

int main() {
  const string aLabel = "aLabel";
  StorageBox sb(1,2,3, aLabel);
}

/* OUTPUT
base constructor called
derived constructor called
*/
