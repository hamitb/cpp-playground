#include <iostream>
#include <exception>

using namespace std;

struct MyException: public exception {
    const char* what() const throw() {
      return "C++ custom exception";
    }
};

int main() {
  try {
    throw MyException();
  } catch(MyException &e) {
    cout << "MyException caught" << endl;
    cout << e.what() << endl;
  } catch(exception& e) {
    cout << "Other exceptions" << endl;
  }
}
