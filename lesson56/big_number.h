#pragma once
#include <deque>
#include <iostream>

class BigNumber
{
public:
    enum { BASE = 0x1000000 };
    BigNumber(int = 0);
    BigNumber operator+(const BigNumber &) const;
    BigNumber operator-(const BigNumber &) const;
    BigNumber operator/(const BigNumber &) const;
    BigNumber operator*(const BigNumber &) const;
    BigNumber operator%(const BigNumber &) const;
    bool operator<(const BigNumber &) const;
    bool isZero() const;
    void print(std::ostream &) const;
    std::deque<unsigned> data_;
private:
    unsigned findDiv(const BigNumber &, const BigNumber &) const;
};

std::ostream &operator<<(std::ostream &s, const BigNumber &n);
