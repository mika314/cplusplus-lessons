// Урок 28
// Разбор арифметических выражений
#include <iostream>
#include <string>
#include <cmath>
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
      break;
    }
  }
  return res;
}

float expr();

float func()
{
  struct FuncList
  {
    const char *n; // name
    float (*f)(float); // function
  }; 
  const FuncList funcList[] = {
    { "cos", cos },
    { "sin", sin },
    { "tan", tan },
    { "acos", acos },
    { "asin", asin },
    { "atan", atan },
    { "cosh", cosh },
    { "sinh", sinh },
    { "tanh", tanh },
    { "exp", exp },
    { "log", log },
    { "sqrt", sqrt },
    { "ceil", ceil },
    { "fabs", fabs },
    { "floor", floor },
    { 0, 0 }
  };
  float res;
  string name;
  for (;;)
  {
    char c = cin.get();
    if (c >= 'a' && c <= 'z')
      name += c;
    else
    {
      cin.putback(c);
      break;
    }
  }
  res = expr();
  for (const FuncList *i = funcList; i -> n != 0; ++i)
  {
    if (i -> n == name)
      return i -> f(res);
  }
  cerr << "Неизвестная функция: " << name << endl;
  return res;
}

float hiLevel()
{
  float x;
  char c = cin.get();
  if (c == '(')
  {
    x = expr();
    cin.get();
  }
  else
  {
    cin.putback(c);
    if (isdigit(c))
      x = number();
    else
      x = func();
  }
  return x;
}

float factor()
{
  float x = hiLevel();
  while (true)
  {
    char c = cin.get();
    switch (c)
    {
    case '*':
      x *= hiLevel();
      break;
    case '/':
      x /= factor();
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
  while (true)
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
  cout << "Введите выражение: ";
  float r = expr();
  cout << "Результат: " << r << endl;
}
