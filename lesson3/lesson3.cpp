#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Введите количесто пирожков: " << endl;
  cin >> n;
  cout << "Я собираюсь съесть " << n << " пирожков" << endl;
  for (int i = n; i > 0; --i)
  {
    cout << "Осталось " << i << " пирожков";
    cout << endl;
  }
  if (n > 20)
    cout << "Ой... я лопнул." << endl;
  else
  {
    if (n < 10)
      cout << "Я не наелся." << endl;
    else
      cout << "Уф... чуть не лопнул." << endl;
  }
}
