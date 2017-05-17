#include <iostream>

using std::cout;
using std::endl;

int main() {
  int n = 1;
  int m = 1;

  m = 7, m = m + 1; // Nondeterministic since it's not entirely predictable (,)
  n = 7; n = n + 1; // Deterministic (;)

  cout << m << endl;
  cout << n << endl;

  return 0;
}
