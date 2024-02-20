#include <iostream>
#include "BigNumbers/BigFloat.h"
#include "BigNumbers/BigInteger.h"
#include "BigNumbers/BigInteger.cpp"
#include "BigNumbers/BigFloat.cpp"

int main(){
    BigFloat r1("0.0123");
    BigFloat r2("10000");
    BigFloat r3("2131231");
    r1/=r2;
    std::string t;
    t = r1.toString();
    std::cout << t;
    return 0;
}