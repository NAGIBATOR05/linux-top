#include <iostream>
#include "BigNumbers/BigFloat.h"
#include "BigNumbers/BigInteger.h"
#include "BigNumbers/BigInteger.cpp"
#include "BigNumbers/BigFloat.cpp"

int main(){
    BigFloat r("-034768.010203040506070809123456789");
    r.change_precision(10);
    std::cout << (-r).toString();
    return 0;
}