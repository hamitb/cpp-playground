#include <iostream>
#include <vector>
using std::cout;
using std::endl;

class Something {
public:
  Something(std::vector<int *> input){
    intVector = input;
  }

  void list() {
    for(int i = 0; i < intVector.size() ; i++) {
      cout << *intVector[i] << endl;
    }
  }
private:
  std::vector<int *> intVector;
};

int main() {
  std::vector<int *> aVector;
  int *ip1 = new int;
  int *ip2 = new int;

  *ip1 = 3;
  *ip2 = 7;

  aVector.push_back(ip1);
  aVector.push_back(ip2);

  Something aThing(aVector);
  aVector.clear();

  aThing.list();

  return 0;
}

/* OUTPUT
3
7
*/
