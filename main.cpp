#include <iostream>
#include "BigNumbers/BigFloat.h"
#include "BigNumbers/BigInteger.h"
#include "BigNumbers/BigInteger.cpp"

int main(){
    BigInteger o1;
    BigInteger o2("-00000");
    BigInteger o3("123456");
    BigInteger o4(-123456);
    BigInteger o5(1234567810000000000);
    BigInteger o6("");
    BigInteger o7("1231312");
    BigInteger o8("-123456");
    BigInteger o9("0000000000003124122141241273647813605814783784079412034");
    BigInteger o10("5325");
    std::string a;
    a = o8.toString();
    std::cout << (o4 == o3.abs()) << std::endl;
    return 0;
}