#ifndef LINUX_TOP_BIGFLOAT_H
#define LINUX_TOP_BIGFLOAT_H
#include "BigInteger.h"
#include <iostream>
#include <vector>

class BigFloat{
public:
    using SelfRefBigFloat = const BigFloat&;

    const BigFloat operator-() const;

    friend bool operator!=(SelfRefBigFloat, SelfRefBigFloat);
    friend bool operator==(SelfRefBigFloat, SelfRefBigFloat);
    friend bool operator<(SelfRefBigFloat, SelfRefBigFloat);
    friend bool operator<=(SelfRefBigFloat, SelfRefBigFloat);
    friend bool operator>(SelfRefBigFloat, SelfRefBigFloat);
    friend bool operator>=(SelfRefBigFloat, SelfRefBigFloat);

    BigFloat& operator+=(SelfRefBigFloat);
    BigFloat& operator-=(SelfRefBigFloat);
    BigFloat& operator*=(SelfRefBigFloat);
    BigFloat& operator/=(SelfRefBigFloat);

    friend const BigFloat operator +(SelfRefBigFloat left, SelfRefBigFloat right);
    friend const BigFloat operator -(SelfRefBigFloat left, SelfRefBigFloat right);
    friend const BigFloat operator *(SelfRefBigFloat left, SelfRefBigFloat right);
    friend const BigFloat operator /(SelfRefBigFloat left, SelfRefBigFloat right);

    std::vector<int> get_val();

    BigFloat(const std::string other);
    BigFloat(const BigInteger& num);
    BigFloat(){};
    ~BigFloat() = default;
    std::string toString() const;
private:
    void delete_leadings_zeroes();
    BigInteger numberF;
    int index;
};

#endif