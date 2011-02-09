#include <iostream>
using namespace std;

int main()
{
    cout << "Я собираюсь съесть 10 пирожков" << endl;
    int i = 11;
    while (i <= 10)
    {
        cout << "Пирожок: " << i << endl;
        ++i;
    } 
    cout << "Уф... чуть не лопнул." << endl;
}
