//Урок 21
//Школьный метод нахождения числа Пи
#include <iostream>
using namespace std;

float pi()
{
  float p = 0;
  float z = 1;
  for (int i = 1; i < 100000; i+=2)
  {
    p += z * 4 / i;
    z *= -1;
  }
  return p;
}

int main()
{
  cout << pi() << endl;
}
