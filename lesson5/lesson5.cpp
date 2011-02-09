#include <iostream>

using namespace std;

int main()
{
  float x;
  float y;
  char o;
  char d;
  do 
  {
    cout << "Правило использования число операция число";
    cout << endl << endl;
    cin >> x;
    cin >> o;
    cin >> y;
    cout << x << o << y << "=";
    float r;
    switch (o)
    {
    case '+':
      r = x + y;
      break;
    case '-':
      r = x - y;
      break;
    case '*':
      r = x * y;
      break;
    case '/':
      r = x / y;
      break;
    }
    cout << r << endl;
    cout << "Продолжить (y/n)? ";
    cin >> d;
  } while (d == 'y');
}
