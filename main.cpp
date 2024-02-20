#include <iostream>
#include "BigNumbers/BigFloat.h"
#include "BigNumbers/BigInteger.h"
#include "BigNumbers/BigInteger.cpp"
#include "BigNumbers/BigFloat.cpp"

int main(){
    BigFloat r1("-00000000000034768.010");
    BigFloat r2("000034768.0000000000000000000000000000000000000000000000000000000000000000000000000001");
    r1.change_precision(10);
    std::cout << ((-r1) > r2);
    return 0;
}