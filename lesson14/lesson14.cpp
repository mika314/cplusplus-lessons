// Урок 14
// Двухмерные массивы
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  const int H = 15;
  const int W = 56;
  char m[15][96];
  for (int y = 0; y < H; ++y)
    for (int x = 0; x < W; ++x)
      m[y][x] = '.';
  for (int x = 0; x < W; ++x)
  {
    int y = (sin(1.0 * x * 2 * M_PI / W) + 1) / 2 * H;
    if ((y >= 0) && (y < H))
      m[y][x] = '*';
  }
  for (int y = 0; y < H; ++y)
  {
    for (int x = 0; x < W; ++x)
      cout <<  m[y][x];
    cout << endl;
  }
  
}
