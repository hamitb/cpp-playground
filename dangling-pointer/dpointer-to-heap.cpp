#include <iostream>

using std::cout;
using std::endl;

struct Date {
  int y, m, d;
};

int main() {

  Date* dateP = new Date;
  dateP->y = 1996;
  dateP->m = 1;
  dateP->d = 26;

  Date* dateQ = dateP;
  
  cout << dateP->y << "/" << dateP->m << "/" << dateP->d << endl;

  delete dateQ; // This will not immediately delete memory it will just say that I'm not responsible with this memory anymore do what you want to do

  dateP->y = 2017; // Unpredictable consequences, dateP is dangling pointer
  
  cout << dateP->y << "/" << dateP->m << "/" << dateP->d << endl; // Unpredictable consequences
  
  return 0;
}
