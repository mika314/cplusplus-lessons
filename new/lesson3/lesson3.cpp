// Урок 3
// Условный оператор
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Введите количество пирожков: ";
    cin >> n;
    cout << "Я собираюсь съесть " << n << " пирожков" << endl;
    for (int i = n; i >= 1; --i)
        cout << "Осталось " << i << " пирожков" << endl;
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
