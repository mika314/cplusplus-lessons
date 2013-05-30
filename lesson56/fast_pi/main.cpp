// pi = sum(1 / 16^i * (4 / (8 * i + 1) - 2 / (8 * i + 4) - 1 / (8 * i + 5) - 1 / (8 * i + 6)))
#include <gmpxx.h>
#include <iostream>

int main()
{
    mpq_class piReminer(0);
    for (size_t i = 0;; i += 8)
    {
        piReminer <<= 4;
        mpq_class a1(4, i + 1);
        mpq_class a2(2, i + 4);
        mpq_class a3(1, i + 5);
        mpq_class a4(1, i + 6);
        piReminer += a1 - a2 - a3 - a4;
        mpz_class whole = piReminer.get_num() / piReminer.get_den();
        piReminer -= whole;
        char ch = (whole < 10) ? (whole.get_ui() + '0') : (whole.get_ui() - 10 + 'a');
        std::cout << ch;
        if (i / 8 % 40 == 0)
            std::cout << std::endl;
    }
}
