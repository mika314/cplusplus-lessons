// Урок 15
// Булева логика
#include <iostream>
using namespace std;

int main()
{
  cout << "Проехала поливальная машина(y/n)? ";
  char a;
  cin >> a;
  bool p = (a == 'y');
  cout << "Был дождь(y/n)? ";
  cin >> a;
  bool r = (a == 'y');
  cout << "Свеит солнце(y/n)? ";
  cin >> a;
  bool s = (a == 'y');
  if ((p || r) && !s)
    cout << "Асфальт мокрый" << endl;
  else 
    cout << "Асфальт сухой" << endl;
}
