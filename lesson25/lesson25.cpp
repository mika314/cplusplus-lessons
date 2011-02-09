// Урок 25
// Рекурсия
#include <iostream>
using namespace std;

void t(int r, int b, int e)
{
  int c;
  if (((b == 1) && (e == 2)) || 
      ((b == 2) && (e == 1)))
    c = 3;
  else
  if (((b == 1) && (e == 3)) || 
      ((b == 3) && (e == 1)))
    c = 2;
  else
  if (((b == 2) && (e == 3)) || 
      ((b == 3) && (e == 2)))
    c = 1;
  if (r > 1)
  {
    t(r - 1, b, c);
    cout << b << " -> " << e << endl;
    t(r - 1, c, e);
  }
  else
    cout << b << " -> " << e << endl;
}

int main()
{
  t(3, 1, 3);
}
