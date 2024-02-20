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
            std::cout << numberF.number[0] << std::endl;
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

