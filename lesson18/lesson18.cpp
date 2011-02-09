// Урок18
// Поиск числа в отсортированом массиве
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream f("file.txt");
  const int n = 100;
  int m[n];
  for (int i = 0; i < n; ++i)
    f >> m[i];
  int x;
  cout << "Введите искомое число ";
  cin >> x;
  
  float l = 0;
  float r = 100;
  float a = (l + r) / 2;
  while ((m[(int)a] != x) && (r - l > 1))
  {
    if (m[(int)a] < x)
      l = a;
    else
      r = a;
    a = (l + r) / 2;
  }
  cout << "Число " << x << " находится по индексу " 
       << (int)a;
}
