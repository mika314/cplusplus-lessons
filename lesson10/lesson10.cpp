#include <iostream>
#include <cmath>
using namespace std;

float f(float x)
{
  return x * x - 2;
}

float n(float x1, float x2)
{
  float x = (x2 + x1) / 2;
  while (abs(f(x)) > 0.001)
  {
    if (f(x) > 0)
      x2 = x;
    else 
      x1 = x;
    x = (x2 + x1) / 2;
  }
  return x;
}

int main()
{
  cout << n(0, 100) << endl;
}
