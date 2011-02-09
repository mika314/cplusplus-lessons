// Урок 17
// Пузырьковая сортировка
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int n = 5;
  int a[n];
  ifstream f("file.txt");
  for (int i = 0; i < n; ++i)
  {
    f >> a[i];
    cout << a[i] << endl;
  }
  // soring
  for (int i = n - 1; i >= 1; --i)
    for (int j = 0; j < i; ++j)
    {
      if (a[j] > a[j + 1])
      {
	int foo = a[j];
	a[j] = a[j + 1];
	a[j + 1] = foo;
      }
    }
  cout << endl;
  for (int i = 0; i < n; ++i)
    cout << a[i] << endl;
}
