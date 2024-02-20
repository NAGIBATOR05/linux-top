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