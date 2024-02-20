#include <iostream>
#include "BigNumbers/BigFloat.h"
#include "BigNumbers/BigInteger.h"
#include "BigNumbers/BigInteger.cpp"
#include "BigNumbers/BigFloat.cpp"

int main(){
    BigInteger o1(123);
    BigInteger o2(11);
    BigInteger o3("12100000000000000000000000000000000000000000000000000000121000000000000000000000000000000000000000000000000000000121");
    BigInteger o4(0);
    BigInteger o5(1234567810000000000);
    BigInteger o6("");
    BigInteger o7("1231312");
    BigInteger o8("-100000");
    BigInteger o9("0000000000003124122141241273647813605814783784079412034");
    BigInteger o10(123456789123456789);
    BigInteger k;
    k = o1;
    o3 /= o2;
    std::string a = o3.toString();
    std::cout << a << std::endl;
    return 0;
}