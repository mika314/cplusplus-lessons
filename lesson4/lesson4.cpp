#include <iostream>
using namespace std;

int main()
{
  cout << "Введите количество пирожков: ";
  int n;
  cin >> n;
  cout << "Я собираюсь съесть " << n;
  int o = n % 100;
  if ((o > 10) && (o < 20))
    cout << " пирожков.";
  else
  {
    switch (o % 10)
    {
    case 0:
      cout << " пирожков.";
      break;
    case 1:
      cout << " пирожок.";
      break;
    case 2:
    case 3:
    case 4:
      cout << " пирожка.";
      break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      cout << " пирожков.";
      break;
    }
  }
  cout << endl;
}
