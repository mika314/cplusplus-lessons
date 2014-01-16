// Урок 28
// Разбор арифметических выражений
#include <iostream>
using namespace std;

float number()
{
  int res = 0;
  for (;;)
  {
    char c = cin.get();
    if (c >= '0' && c <= '9')
      res = res * 10 + c - '0';
    else
    {
      cin.putback(c);
      return res;
    }
  }
}

float expr();

float skobki()
{
  char c = cin.get();
  if (c == '(')
  {
    float x = expr();
    cin.get();
    return x;
  }
  else
  {
    cin.putback(c);
    return number();
  }
}

float factor()
{
  float x = skobki();
  for (;;)
  {
    char c = cin.get();
    switch (c)
    {
    case '*':
      x *= skobki();
      break;
    case '/':
      x /= skobki();
      break;
    default:
      cin.putback(c);
      return x;
    }
  }
}

float expr()
{
  float x = factor();
  for (;;)
  {
    char c = cin.get();
    switch (c)
    {
    case '+':
      x += factor();
      break;
    case '-':
      x -= factor();
      break;
    default:
      cin.putback(c);
      return x;
    }
  }
}


int main()
{
  setlocale(LC_ALL, "Russian");
  cout << "Введите выражение: ";
  float res = expr();
  cout << "Результат: " << res << endl;
  while (true) {}
}
