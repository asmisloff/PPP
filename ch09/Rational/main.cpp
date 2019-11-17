#include "rational.h"
#include <iostream>

int main() {
    Rational r1(1, 2);
    Rational r2(3, -3);
    
    auto print = [](const Rational& r) { 
        return "(" + r.to_string() + " == " + r.normalized() + ")";
    };
    
    std::cout << "r1 = " << print(r1) << std::endl;
    std::cout << "r2 = " << print(r2) << std::endl;
    std::cout << "r1 - r2 = " << print(r1 - r2) << std::endl;
    std::cout << "r1 * r2 = " << print(r1 * r2) << std::endl;
    
    return 0;
}
