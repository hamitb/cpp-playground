#include <iostream>

using std::cout;
using std::endl;

template <class T, size_t N>
size_t array_size(T (&array)[N]) {  // Not works with dynamically allocated memory
    return N;
}

int main() {
  float v1[] = {2.0, 3.0, 5.0, 7.0};
  float v2[10];

  cout << array_size(v1) << endl;   // 4
  cout << array_size(v2) << endl;   // 10

  return 0;
}
