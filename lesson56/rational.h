#pragma once
#include "big_number.h"
#include <iostream>

class Rational
{
public:
    Rational(BigNumber numerator, BigNumber denumerator = 1);
    Rational operator-(const Rational &y) const;
    Rational operator+(const Rational &y) const;
    Rational operator*(const Rational &y) const;
    Rational operator/(const Rational &y) const;
    void print(std::ostream &stream) const;
private:
    BigNumber numerator_;
    BigNumber denominator_;
};

std::ostream &operator<<(std::ostream &, const Rational &);
