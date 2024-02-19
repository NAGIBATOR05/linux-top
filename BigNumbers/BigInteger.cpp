#include "BigInteger.h"
using SelfRefBigInt = const BigInteger&;

BigInteger::BigInteger(const long long& other) {
    if (other < 0) {
        sign = Sign::negative;
    } else if (other == 0) {
        sign = Sign::zero;
    } else {
        sign = Sign::positive;
    }
    long long copy = std::abs(other);
    while (copy != 0) {
        number.push_back(copy % kSystem);
        copy /= kSystem;
    }
}

BigInteger::BigInteger(const std::string other) {
    if (other.size() == 1 && other[0] == '0') {
        BigInteger::sign = Sign::zero;
        return;
    }
    if (other.size() == 0) {
        return;
    }
    BigInteger::sign = Sign::positive;
    int ind = 0;
    if (other[0] == '-') {
        BigInteger::sign = Sign::negative;
        ++ind;
    }
    while (other[ind] == '0' && ind < other.size()) {
        ++ind;
    }
    if (ind == other.size()) {
        BigInteger::sign = Sign::zero;
        return;
    }
    std::string current;
    for (int i = other.size() - 1; i >= ind; --i) {
        current = other[i] + current;
        if(current.size() == 9){
            number.push_back(stoi(current));
            current = "";
        }
    }
    number.push_back(stoi(current));
}

const BigInteger BigInteger::operator-() const {
    BigInteger result = *this;
    if (result.sign == Sign::positive) {
        result.sign = Sign::negative;
    } else if (sign == Sign::negative) {
        result.sign = Sign::positive;
    }
    return result;
}

std::string BigInteger::toString() const {
    if (sign == Sign::zero) {
        return "0";
    }
    std::string output_string;
    for (size_t i = number.size(); i > 0; i--) {
        for (size_t j = 0; j < (kDigit_size - std::to_string(number[i - 1]).size()) && i != number.size(); j++) {
            output_string += '0';
        }
        for (size_t j = 0; j < std::to_string(number[i - 1]).size(); j++) {
            output_string.push_back(std::to_string(number[i - 1])[j]);
        }
    }
    if (sign == Sign::negative) {
        output_string = "-" + output_string;
    }
    return output_string;
}

bool operator==(SelfRefBigInt first, SelfRefBigInt second) {
    if (first.signum() != second.signum() || first.digits().size() != second.digits().size()) {
        return false;
    }
    for (size_t i = 0; i < first.digits().size(); i++) {
        if (first.digits()[i] != second.digits()[i]) {
            return false;
        }
    }
    return true;
}

bool operator<(SelfRefBigInt first, SelfRefBigInt second) {
    if (first == second) {
        return false;
    }
    if (first.signum() > second.signum()) {
        return false;
    } if (first.signum() < second.signum()) {
        return true;
    } if (first.signum() == Sign::negative) {
        return -second < -first;
    } if (first.digits().size() > second.digits().size()) {
        return false;
    } if (first.digits().size() < second.digits().size()) {
        return true;
    } for (size_t i = first.digits().size(); i > 0; i--) {
        if (first.digits()[i - 1] > second.digits()[i - 1]) {
            return false;
        } if (first.digits()[i - 1] < second.digits()[i - 1]) {
            return true;
        }
    }
    return true;
}

bool operator!=(SelfRefBigInt first, SelfRefBigInt second) {
    return !(first == second);
}

bool operator<=(SelfRefBigInt first, SelfRefBigInt second) {
    return !(second < first);
}

bool operator>(SelfRefBigInt first, SelfRefBigInt second) {
    return second < first;
}

bool operator>=(SelfRefBigInt first, SelfRefBigInt second) {
    return !(first < second);
}

const BigInteger BigInteger::abs() const {
    BigInteger copy = *this;
    if (copy.sign == Sign::negative) {
        copy.sign = Sign::positive;
    }
    return copy;
}