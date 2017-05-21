#include <iostream>
#include <vector>
using std::cout;
using std::endl;

class Something {
public:
  Something(std::vector<int *> input){
    intVector = input;
  }

  ~Something() {
    for(int i = 0; i < intVector.size(); i++) {
      if(intVector[i]){
        cout << "Deleting " << i << "th" << " element of vector member" << endl;
        delete intVector[i];
      }
    }
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
  int *ip3 = new int;

  *ip1 = 3;
  *ip2 = 7;
  *ip3 = 5;

  aVector.push_back(ip1);
  aVector.push_back(ip2);
  aVector.push_back(ip3);

  Something* aThing = new Something(aVector);
  aVector.clear();

  aThing->list();

  delete aThing;


  return 0;
}

/* OUTPUT
3
7
*/
