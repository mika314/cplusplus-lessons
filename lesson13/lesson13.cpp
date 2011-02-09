// Урок 13
// Введение в массивы
#include <iostream>
using namespace std;

class A
{
public:
  int x;
  int y;
};

int main()
{
  A a[20];
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
  {
    a[i].x = i * i;
    a[i].y = i;
  }

  for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
    cout << a[i].x << endl;
}
