#include <iostream>
#include "BigNumbers/BigFloat.h"
#include "BigNumbers/BigInteger.h"
#include "BigNumbers/BigInteger.cpp"

int main(){
    BigInteger o1;
    BigInteger o2(000000);
    BigInteger o3(123456);
    BigInteger o4(-123456);
    BigInteger o5(1234567810000000000);
    BigInteger o6("");
    BigInteger o7("1231312");
    BigInteger o8("-1241412");
    BigInteger o9("0000000000003124122141241273647813605814783784079412034");
    BigInteger o10("-0");
    std::string a;
    a = o1.toString();
    std::cout << a;
    return 0;
}