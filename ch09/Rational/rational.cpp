#include <stdexcept>
#include "rational.h"

unsigned int greatest_common_divisor(int a, int b) {
    a = abs(a), b = abs(b);
    if (a % b == 0) {
        return b;
    }
    if (b % a == 0) {
        return a;
    }
    if (a > b) {
        return greatest_common_divisor(a%b, b);
    }
    return greatest_common_divisor(a, b%a);
}

unsigned int least_common_multiple(unsigned int a, unsigned int b) {
    return (a*b)/greatest_common_divisor(a,b);
}

Rational::Rational(int num, int den)
{
    if (den == 0) { throw std::invalid_argument("Zero denominator"); }
    if (num == 0) { den = 1; }
    if (den < 0) { num *= -1; den *= -1; }
    _numerator = num, _denominator = den;
    reduce();
}

const Rational& Rational::reduce()
{
    int gcd = greatest_common_divisor(_numerator, _denominator);
    _numerator /= gcd;
    _denominator /= gcd;
    return *this;
}


std::string Rational::normalized() const
{
    int rem = _numerator % _denominator;
    
    if (integer_part() == 0) {
        return std::to_string(_numerator) + '/' + std::to_string(_denominator);
    }
    else if (rem == 0) {
        return std::to_string(integer_part());
    }
    else
        return std::to_string(integer_part()) + " + " + std::to_string(rem) + '/' + std::to_string(_denominator);
}

std::ostream& operator<<(std::ostream& out, const Rational& r)
{
    return out << r.to_string();
}

const Rational operator+(const Rational& left, const Rational& right)
{
    if (left.denominator() == right.denominator()) {
        return Rational(left.numerator() + right.numerator(), left.denominator()).reduce();
    }
    else {
        int denom = least_common_multiple(left.denominator(), right.denominator());
        int num = left.numerator() * (denom / left.denominator()) + right.numerator() * (denom / right.denominator());
        return Rational(num, denom).reduce();
    }
}

const Rational operator-(const Rational& left, const Rational& right)
{
    if (left.denominator() == right.denominator()) {
        return Rational(left.numerator() - right.numerator(), left.denominator())
               .reduce();
    }
    else {
        int denom = least_common_multiple(left.denominator(), right.denominator());
        int num = left.numerator() * (denom / left.denominator())
                - right.numerator() * (denom / right.denominator());
        return Rational(num, denom).reduce();
    }
}

const Rational operator*(const Rational& left, const Rational& right)
{
    return Rational(left.numerator() * right.numerator(),
                    left.denominator() * right.denominator())
           .reduce();
}
