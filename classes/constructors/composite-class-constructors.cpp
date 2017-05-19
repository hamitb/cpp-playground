#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Label {
public:
  Label(const string& name, const string& address) { m_name = name; m_address = address; }
  string m_name;
  string m_address;
};

class Box {
public:
  Box(int width, int length, int height)
    : m_width(width), m_length(length), m_height(height) // member init list 
    {}
private:
  int m_height;
  int m_length;
  int m_width;
};

class StorageBox: public Box {
public:
  StorageBox(int width, int length, int height, Label label)
    : Box(width, length, height), m_label(label) {}
private:
  Label m_label;
};

int main() {
  // passing a named Label
  Label label1("some_name", "some_address");
  StorageBox sb1(1, 2, 3, label1);

  //passing a temporary label
  StorageBox sb2(3, 4, 5, Label("another_name", "another_address"));
}

