#include <iostream>
#include "BigNumbers/BigFloat.h"
#include "BigNumbers/BigInteger.h"
#include "BigNumbers/BigInteger.cpp"
#include "BigNumbers/BigFloat.cpp"

int main(){
    BigFloat r("0032132300000123456789.010203040506070809123456789");
    std::string t;
    t = r.toString();
    std::cout << t;
    return 0;
}