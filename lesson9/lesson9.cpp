#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  srand(time(0));
  bool done;
  do
  {
    int i = rand() % 100;
    while (true)
    {
      cout << "Я загадал число, какое? ";
      int j;
      cin >> j;
      if (i > j)
	cout << "Мое число больше." << endl;
      else
      {
	if (i < j)
	  cout << "Мое число меньше." << endl;
	else
	{
	  cout << "Ты угадал." << endl;
	  break;
	}
      }
    }
    cout << "Продолжить (y/n)? ";
    char c;
    cin >> c;
    done = (c != 'y');
  } while (!done);
}
