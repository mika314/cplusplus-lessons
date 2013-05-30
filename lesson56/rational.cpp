#include "rational.h"

Rational::Rational(BigNumber numerator, BigNumber denumerator):
    numerator_(numerator),
    denominator_(denumerator)
{}

Rational Rational::operator-(const Rational &y) const
{
    auto numerator = numerator_ * y.denominator_ - y.numerator_ * denominator_;
    auto denominator = denominator_ * y.denominator_;
    return Rational(numerator, denominator);
}

Rational Rational::operator+(const Rational &y) const
{
    auto numerator = numerator_ * y.denominator_ + y.numerator_ * denominator_;
    auto denominator = denominator_ * y.denominator_;
    return Rational(numerator, denominator);
}

Rational Rational::operator*(const Rational &y) const
{
    return Rational(numerator_ * y.numerator_, denominator_ * y.denominator_);
}

Rational Rational::operator/(const Rational &y) const
{
    return Rational(numerator_ * y.denominator_, denominator_ * y.numerator_);
}

std::ostream &operator<<(std::ostream &stream, const Rational &number)
{
    number.print(stream);
    return stream;
}

void Rational::print(std::ostream &stream) const
{
    stream << numerator_ / denominator_ << ".";
    auto r = numerator_ % denominator_;
    auto d = denominator_;
    while (!d.isZero())
    {
        d = d / 10;
        r = r * 10;
        stream << r / denominator_;
        r = r % denominator_;
    }
}
