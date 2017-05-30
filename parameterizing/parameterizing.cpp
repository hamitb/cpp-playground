#include <iostream>
#include <math.h>

using std::cout;
using std::endl;


typedef float Vector[];

const int n = 3;

Vector v = {3.0, 4.0, 0.0};

// Always perform same computation, useless.
float length() {
  float s = 0.0;
  for(int i = 0; i < n; i++)
    s += v[i] * v[i];

  return sqrt(s);
}

// Now we can write funciton calls, such as length(v1), length(v2)
float length(Vector v) {
  float s = 0.0;
  for(int i = 0; i < n; i++)
    s += v[i] * v[i];

  return sqrt(s);
}

// Far more usefull
float length(Vector v, int n) {
  float s = 0.0;
  for(int i = 0; i < n; i++)
    s += v[i] * v[i];

  return sqrt(s);
}
