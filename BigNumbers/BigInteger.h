#ifndef LINUX_TOP_BIGINTEGER_H
#define LINUX_TOP_BIGINTEGER_H
#include <iostream>
#include <vector>

enum class Sign {
    negative,
    zero,
    positive
};

Sign signum(const long long& integer) {
    if (integer > 0) {
        return Sign::positive;
    }
    if (integer == 0) {
        return Sign::zero;
    }
    return Sign::negative;
}

class BigInteger {
public:
    //
private:
    Sign sign = Sign::zero;
    std::vector<int> number;
};

#endif
