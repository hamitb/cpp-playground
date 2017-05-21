#include <iostream>

using std::cout;
using std::endl;

class printData {
public:
  void print(int i) {
    cout << "Printing int: " << i << endl;
  }

  void print(double f) {
    cout << "Printing float: " << f << endl;
  }
  
  void print(char* c) {
    cout << "Printing float: " << c << endl;
  }

};

int main() {
  printData pd;

  pd.print(5);

  pd.print(100.101);

  pd.print("Bonne journée");

  return 0;
}
