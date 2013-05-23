#include "big_number.h"
#include <cstdint>

BigNumber::BigNumber(int n)
{
    while (n > 0)
    {
        data_.push_back(n % BASE);
        n /= BASE;
    }
}

BigNumber BigNumber::operator+(const BigNumber &y) const
{
    BigNumber result;
    int carrier = 0;
    for (auto i = 0u; i < std::max(y.data_.size(), data_.size()); ++i)
    {
        auto xx = i >= data_.size() ? 0 : data_[i];
        auto yy = i >= y.data_.size() ? 0 : y.data_[i];
        uint64_t r = 0ULL + xx + yy + carrier;
        result.data_.push_back(r % BASE);
        carrier = r / BASE;
    }
    if (carrier != 0)
        result.data_.push_back(carrier);
    return result;
}

BigNumber BigNumber::operator-(const BigNumber &y) const
{
    BigNumber result;
    int carrier = 0;
    for (auto i = 0u; i < std::max(y.data_.size(), data_.size()); ++i)
    {
        auto xx = i >= data_.size() ? 0 : data_[i];
        auto yy = i >= y.data_.size() ? 0 : y.data_[i];
        if (0LL + xx >= 0LL + yy + carrier)
        {
            result.data_.push_back(xx - yy - carrier);
            carrier = 0;
        }
        else
        {
            result.data_.push_back(BASE + xx - yy - carrier);
            carrier = 1;
        }
    }
    return result;
}

BigNumber BigNumber::operator*(const BigNumber &y) const
{
    BigNumber result;
    for (auto i = 0u; i < y.data_.size(); ++i)
    {
        unsigned carrier = 0;
        BigNumber k;
        for (auto j = 0u; j < i; ++j)
            k.data_.push_back(0);
        for (auto j = 0u; j < data_.size(); ++j)
        {
            auto xx = data_[j];
            auto yy = y.data_[i];
            uint64_t r = 1ULL * xx * yy + carrier;
            k.data_.push_back(r % BASE);
            carrier = r / BASE;
        }
        if (carrier != 0)
            k.data_.push_back(carrier);
        result = result + k;
    }
    return result;
}

BigNumber BigNumber::operator/(const BigNumber &y) const
{
    BigNumber result;
    BigNumber l;
    for (auto i = 0u; i < data_.size(); ++i)
    {
        l.data_.push_front(data_[data_.size() - i - 1]);
        auto div = findDiv(l, y);
        result.data_.push_front(div);
        l = l - y * BigNumber(div);
    }
    return result;
}

bool BigNumber::operator<(const BigNumber &y) const
{
    for (int i = std::max(data_.size(), y.data_.size()) - 1; i >= 0; --i)
    {
        
        auto xx = i >= static_cast<int>(data_.size()) ? 0 : data_[i];
        auto yy = i >= static_cast<int>(y.data_.size()) ? 0 : y.data_[i];
        if (xx != yy)
            return xx < yy;
    }
    return false;
}


unsigned BigNumber::findDiv(const BigNumber &dividend, const BigNumber &divisor) const
{
    unsigned first = 0;
    unsigned last = BASE;
    
    unsigned it;
    int64_t count, step;
    count = last - first;
    while (count > 0)
    {
        it = first;
        step = count / 2;
        it += step;
        if (!(dividend < BigNumber(it) * divisor))
        {
            first = ++it;
            count -= step + 1;
        }
        else
            count = step;
    }
    return first - 1;
}
