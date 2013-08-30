// Урок 59
// Умножение
#include <iostream>
#include <iomanip>
using namespace std;

int mul(int x, int y)
{
    int res = 0;
    for (int i = 0; i < y; ++i)
        res += x;
    return res;
}

int fastMul(int x, int y)
{
    int res = 0;
    int n;
    int acc;
    while (y > 0)
    {
        n = 1;
        acc = x;
        while (n + n <= y)
        {
            acc += acc;
            n += n;
        }
        res += acc;
        y -= n;
    }
    return res;
}

int main()
{
    for (int x = 0; x < 10; ++x)
    {
        for (int y = 0; y < 10; ++y)
            cout << x << "*" << y << "=" << left << setw(3) << fastMul(x, y);
        cout << endl;
    }
    for (int i = 0; i < 10; ++i)
        cout << "2 * 1000000000 = " << fastMul(2, 1000000000) << endl;
}
