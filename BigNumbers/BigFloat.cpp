#include "BigFloat.h"
#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) x.begin(), x.end()

using SelfRefBigFloat = const BigFloat&;

std::vector<int> BigFloat::get_val() {
    std::vector<int> str = numberF.number;
    std::reverse(all(str));
    return str;
}
BigFloat::BigFloat(const BigInteger &num) {
    for (int i = 0; i < num.number.size(); ++i) {
        numberF.number.push_back(num.number[i]);
    }
    numberF.sign = num.sign;
    index = 0;
}

BigFloat::BigFloat(std::string s) {
    if (s.size() == 1 && s[0] == '0') {
        BigFloat::numberF.sign = Sign::zero;
        return;
    }
    BigFloat::index = 0;
    BigFloat::numberF.sign = Sign::positive;
    if (s.size() == 0) {
        return;
    }
    int ind = 0;
    if (s[0] == '-') {
        BigFloat::numberF.sign = Sign::negative;
        ++ind;
    }
    while (s[ind] == '0' && ind < s.size()) {
        ++ind;
    }
    if (ind == s.size()) {
        BigFloat::numberF.sign = Sign::zero;
        return;
    }
    std::string current;
    int toc = s.find(".");
    if(toc >= 0) {
        BigFloat::index = (s.size() - toc + 7)/9;
        int point = s.size() - 1 - toc;
        std::string pon;
        for (int i = 0; i < (9 - point%9)%9; i++) {
            pon = pon + "0";
        }
        s = s + pon;
    }
    for (long long i = s.size() - 1; i >= ind; --i) {
        if (s[i] == '.') {
            continue;
        }
        current = s[i] + current;
        if(current.size() == 9){
            numberF.number.push_back(stoi(current));
            current = "";
        }
    }
    if(current.size()!= 0) {
        numberF.number.push_back(stoi(current));
    }
    BigFloat::delete_leadings_zeroes();
}

void BigFloat::delete_leadings_zeroes() {
    if (BigFloat::numberF.sign == Sign::zero) {
        return;
    }
    std::vector<int> v = BigFloat::numberF.number;
    int cnt = 0;
    while (BigFloat::index > 0 && BigFloat::numberF.number[cnt] == '0') {
        --BigFloat::index;
        ++cnt;
    }
    BigFloat::numberF.number.clear();
    for (int i = cnt; i < v.size(); ++i) {
        BigFloat::numberF.number.push_back(v[i]);
    }
}

std::string BigFloat::toString() const {
    if (numberF.sign == Sign::zero) {
        return "0";
    }
    std::string output_string;
    if(numberF.number.size() == index){
        output_string += '0';
    }
    for (size_t i = numberF.number.size(); i > index ; i--) {
        for (size_t j = 0; j < std::to_string(numberF.number[i - 1]).size(); j++) {
            output_string.push_back(std::to_string(numberF.number[i - 1])[j]);
        }
    }
    if(index > 0){
        output_string += '.';
    }
    for (size_t i = index; i > 0 ; i--) {
        for (size_t j = 0; j < 9; j++) {
            int len = std::to_string(numberF.number[i - 1]).size();
            if ((9 - len) > j) {
                output_string.push_back('0');
            }else {
                output_string.push_back(std::to_string(numberF.number[i - 1])[j - (9-len)]);
            }
        }
    }
    if (numberF.sign == Sign::negative) {
        output_string = "-" + output_string;
    }
    return output_string;
}

void BigFloat::change_precision(int x) {
    if(index >= x){
        return;
    }
    else{
        for(int i = x-index; i > 0; i--){
            numberF.number.insert(numberF.number.begin(), 0);
        }
        index = x;
    }
}

const BigFloat BigFloat::operator-() const {
    BigFloat result = *this;
    if (result.numberF.sign == Sign::positive) {
        result.numberF.sign = Sign::negative;
    } else if (numberF.sign == Sign::negative) {
        result.numberF.sign = Sign::positive;
    }
    return result;
}

int zeroes_of_head(SelfRefBigFloat x){
    int x_digits = x.numberF.number.size();
    for(int i = 0; i < x.index; i++){
        if(x.numberF.number[i] == 0){
            x_digits--;
        }else{
            return x_digits;
        }
    }
    return x_digits;
};

bool operator==(SelfRefBigFloat first, SelfRefBigFloat second) {
    int first_digits = first.numberF.number.size();
    int size_first = zeroes_of_head(first);
    int second_digits = second.numberF.number.size();
    int size_second = zeroes_of_head(second);
    if (first.numberF.sign != second.numberF.sign || size_first != size_second ||
    first.index - (first_digits - size_first) != second.index - (second_digits - size_second)) {
        return false;
    }
    for (size_t i = 0; i < size_second; i++) {
        if (first.numberF.number[(first_digits - size_first) + i] != second.numberF.number[(second_digits - size_second)+i]) {
            return false;
        }
    }
    return true;
}

bool operator<(SelfRefBigFloat first, SelfRefBigFloat second) {
    if (first == second) {
        return false;
    }
    if (first.numberF.sign > second.numberF.sign) {
        return false;
    }
    if (first.numberF.sign < second.numberF.sign) {
        return true;
    }
    if (first.numberF.sign == Sign::negative) {
        return -second < -first;
    }
    int first_digits = first.numberF.number.size();
    int size_first = zeroes_of_head(first);
    int second_digits = second.numberF.number.size();
    int size_second = zeroes_of_head(second);
    if (first_digits - first.index > second_digits - second.index) {
        return false;
    }
    if (first_digits - first.index < second_digits - second.index) {
        return true;
    }
    for (size_t i = 0; i < std::min(first_digits, second_digits + first_digits - first.index); i++) {
        if (first.numberF.number[first_digits - i - 1] > second.numberF.number[second_digits - i - 1]) {
            return false;
        }if (first.numberF.number[first_digits - i - 1] < second.numberF.number[second_digits - i - 1]) {
            return true;
        }
    }
    if(size_first > size_second) {
        return false;
    }if(size_first < size_second){
        return true;
    }
    return true;
}

bool operator!=(SelfRefBigFloat first, SelfRefBigFloat second) {
    return !(first == second);
}

bool operator<=(SelfRefBigFloat first, SelfRefBigFloat second) {
    return !(second < first);
}

bool operator>(SelfRefBigFloat first, SelfRefBigFloat second) {
    return second < first;
}

bool operator>=(SelfRefBigFloat first, SelfRefBigFloat second) {
    return !(first < second);
}

BigFloat& BigFloat::operator+=(SelfRefBigFloat other) {
    BigFloat temp = other;
    if(temp.index > index){
        this -> change_precision(other.index);
    }else{
        temp.change_precision(index);
    }
    numberF += temp.numberF;
    return *this;
}

BigFloat& BigFloat::operator-=(SelfRefBigFloat other) {
    BigFloat temp = other;
    if(temp.index > index){
        this -> change_precision(other.index);
    }else{
        temp.change_precision(index);
    }
    numberF -= temp.numberF;
    return *this;
}

BigFloat& BigFloat::operator*=(SelfRefBigFloat other) {
    BigFloat temp = other;
    numberF *= temp.numberF;
    index += temp.index;
    for(int i = temp.index; i > 0; i--){
        numberF.number.push_back(0);
    }
    return *this;
}

BigFloat& BigFloat::operator/=(SelfRefBigFloat other){
    BigFloat temp = other;
    this ->change_precision(100);
    numberF /= other.numberF;
    index -= other.index;
    return *this;
}