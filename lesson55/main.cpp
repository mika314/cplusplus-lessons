// Урок 55
// Большие числа
#include <iostream>
#include <iomanip>
#include "big_number.h"
using namespace std;

int main()
{
    BigNumber x(135);
    BigNumber y(7);
    auto z = x / y;
    for (auto i = z.data_.rbegin(); i != z.data_.rend(); ++i)
        cout << *i << " ";
    cout << endl;
    // double pi = 0;
    // double k = 1;
    // for (int i = 0; i < 5; ++i)
    // {
    //     pi += k * (4.0 / (8.0 * i + 1.0) -  2.0 / (8.0 * i + 4.0) - 1.0 / (8.0 * i + 5.0) - 1.0 / (8.0 * i + 6.0));
    //     k /= 16.0;
    // }
    // cout << std::setprecision(10) << pi << endl;
}
