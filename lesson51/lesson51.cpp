// Урок 51
// Деление
#include <iostream>
using namespace std;

int main()
{
    int x = 355;
    int y = 113;
    
    cout << x / y << ".";
    for (int i = 0; i < 2000; ++i)
    {
        x = x % y * 10;
        if (x == 0)
            break;
        cout << x / y;
    }
    cout << endl;
}
