#pragma once
#include <deque>

class BigNumber
{
public:
    enum { BASE = 10 };
    BigNumber(int = 0);
    BigNumber operator+(const BigNumber &) const;
    BigNumber operator-(const BigNumber &) const;
    BigNumber operator/(const BigNumber &) const;
    BigNumber operator*(const BigNumber &) const;
    bool operator<(const BigNumber &) const;
    std::deque<unsigned> data_;
private:
    unsigned findDiv(const BigNumber &, const BigNumber &) const;
};
