#ifndef LINUX_TOP_BIGINTEGER_H
#define LINUX_TOP_BIGINTEGER_H
#include <iostream>
#include <vector>

enum class Sign {
    negative,
    zero,
    positive
};

class BigInteger {
public:
    static const size_t kDigit_size = 9;
    static const int kSystem = 1000000000;

    const BigInteger operator-() const;

    BigInteger(const long long& other);
    BigInteger(const std::string other);
    BigInteger(){}
    ~BigInteger() = default;
private:
    std::string toString() const;
    Sign sign = Sign::zero;
    std::vector<int> number;
};

#endif
