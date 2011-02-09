// Урок 16
// Чтение из файла, запись в файл
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream f("file.txt");
  while (true)
  {
    int v;
    f >> v;
    if (!f.eof())
      cout << v << endl;
    else
      break;
  }
}
