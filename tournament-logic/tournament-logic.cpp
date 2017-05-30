#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> aVector;

  int x = 3;
  int y = 4;

  x = x > 4 ? 10 : y=5,7;

  cout << x << "," << y << endl;

  for(int i = 0; i < 8; i++) {
    aVector.push_back(i);
  }

  for(int i = 0; i < aVector.size(); i++) {
    cout << aVector[i] << " ";
  }
  cout << endl;

  int i = 1;

  while(aVector.size() != 1) {
    int winner = aVector.front() < *(aVector.end()-i) ? aVector.front() : *(aVector.end()-i);

    aVector.erase(aVector.begin());
    
    aVector.erase(aVector.end()-i);
    
    aVector.push_back(winner);
    
    i = (aVector.end()-i) == (aVector.begin()) ? 0 : i;
    
    i++;


    for(int i = 0; i < aVector.size(); i++) {
      cout << aVector[i] << " ";
    }
    
    cout << endl;
  }
}
/* OUTPUT
0 1 2 3 4 5 6 7
1 2 3 4 5 6 0
2 3 4 5 0 1
3 4 0 1 2
0 1 2 3
1 2 0
0 1
0
*/
