#include <iostream>
#include "BigNumbers/BigFloat.h"
#include "BigNumbers/BigInteger.h"
#include "BigNumbers/BigInteger.cpp"
#include "BigNumbers/BigFloat.cpp"
#include <algorithm>
#include <chrono>

#define all(x) x.begin(), x.end()
void show(BigInteger a) {
    std::string temp;
    temp = a.toString();
    std::cout << temp << std::endl;
}

void show(BigFloat a) {
    std::string temp;
    temp = a.toString();
    std::cout << temp << std::endl;
}

BigFloat calculate_pi(int idx) {
    clock_t start, finish;
    start = clock();
    BigFloat Pi("0");
    BigFloat deg_16("1");
    std::string prec = "0.";
    int idx1 = idx;
    while (idx1 > 0) {
        prec += '0';
        --idx1;
    }
    prec += '1';
    BigFloat prc(prec);
    BigFloat res("0");
    BigFloat k("0");
    do  {
        res = (BigFloat("1") / deg_16);
        BigFloat res1 = (BigFloat("4") / (BigFloat("8") * k + BigFloat("1"))) - (BigFloat("2") / (BigFloat("8") * k + BigFloat("4"))) -
                        (BigFloat("1") / (BigFloat("8") * k + BigFloat("5"))) - (BigFloat("1") / (BigFloat("8") * k + BigFloat("6")));
        res = res * res1;
        Pi = Pi + res;
        deg_16 = deg_16 * BigInteger("16");
        k = k + BigFloat("1");
    } while(res > prc);
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    std::cout<<duration<<std::endl;
    return Pi;
}
int main(){
    show(calculate_pi(100));

    BigFloat r1("3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");
    BigFloat r2("3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");
    BigFloat r4("9");

    //Bigoat222 r5("1000000000000000000000000000000");
    //BigInteger r1("100000");
    //BigInteger r2("100000");
    BigFloat r3 = r1/r4;
    //BigInteger r3 = r1*r2;
    //r3.change_precision(10);
    //show(r3);
    r3.delete_leadings_zeroes();
    //show(r3);
    return 0;
}