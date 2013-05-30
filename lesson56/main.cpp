// Урок 55
// Большие числа
#include <iostream>
#include <iomanip>
#include "rational.h"
using namespace std;

int main()
{
    Rational pi = BigNumber(0);
    Rational k = BigNumber(1);
    for (int i = 0; i < 10; ++i)
    {
        pi = pi + k * (Rational(4,  8 * i + 1) -  Rational(2, 8 * i + 4) - Rational(1, 8 * i + 5) - Rational(1, 8 * i + 6));
        k = k / Rational(16);
        cout << pi << endl;
    }
}
