#include <iostream>
#include <cmath>
using namespace std;

float f(float x)
{
  cout << (int)x << endl;
  while (true)
  {
    cout << "Правильно (+/-/=)? ";
    char c;
    cin >> c;
    switch (c)
    {
    case '+': return +1;
    case '-': return -1;
    case '=': return 0;
    }
    cout << "Вы ввели неправильный символ, повторите ввод.";
    cout << endl;
  }
}

float n(float x1, float x2)
{
  float x = (x1 + x2) / 2;
  float y = f(x);
  while (abs(y) > 0.001)
  {
    if (y > 0)
      x1 = x;
    else
      x2 = x;
    x = (x1 + x2) / 2;
    y = f(x);
  }
  return x;
}

int main()
{
  cout << "Вы загодали: " << (int)n(0, 100);
}
