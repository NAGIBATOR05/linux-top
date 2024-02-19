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
    using SelfRefBigInt = const BigInteger&;
    static const size_t kDigit_size = 9;
    static const int kSystem = 1000000000;

    const BigInteger operator-() const;

    Sign& signum() {return sign;}
    const Sign& signum() const {return sign;}
    const std::vector<int>& digits() const {return number;}

    friend bool operator!=(SelfRefBigInt, SelfRefBigInt);
    friend bool operator==(SelfRefBigInt, SelfRefBigInt);
    friend bool operator<(SelfRefBigInt, SelfRefBigInt);
    friend bool operator<=(SelfRefBigInt, SelfRefBigInt);
    friend bool operator>(SelfRefBigInt, SelfRefBigInt);
    friend bool operator>=(SelfRefBigInt, SelfRefBigInt);

    BigInteger(const long long& other);
    BigInteger(const std::string other);
    BigInteger(){}
    ~BigInteger() = default;
    std::string toString() const;
private:
    Sign sign = Sign::zero;
    std::vector<int> number;
};

#endif
