#include <stdexcept>
#include "rational.h"

#define greatest_common_divisor(a, b) _gcd(abs(a), abs(b))
int _gcd(int a, int b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return _gcd(a%b, b);
    return _gcd(a, b%a);
}

int least_common_multiple(int a, int b) {
    return abs((a*b)/greatest_common_divisor(a,b));
}

Rational::Rational(int num, int den)
{
    if (den == 0) {
        throw std::invalid_argument("Zero denominator");
    }
    
    if (num == 0) { den = 1; }
    if (den < 0) { num *= -1; den *= -1; }
    _numerator = num;
    _denominator = den;
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
    return out << r.numerator() << '/' << r.denominator();
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
    if (left._denominator == right._denominator) {
        return Rational(left._numerator - right._numerator, left._denominator).reduce();
    }
    else {
        int denom = least_common_multiple(left._denominator, right._denominator);
        int num = left._numerator * (denom / left._denominator)
                - right._numerator * (denom / right._denominator);
        Rational temp(num, denom);
        return temp.reduce();
    }
}

const Rational operator*(const Rational& left, const Rational& right)
{
    return Rational(left._numerator * right._numerator,
                    left._denominator * right._denominator)
           .reduce();
}

const Rational operator/(const Rational& left, const Rational& right)
{
    return Rational(left._numerator * right._denominator,
                    left._denominator * right._numerator)
           .reduce();
}

bool operator==(const Rational& left, const Rational& right)
{
    return (left._numerator == right._numerator)
        && (left._denominator == right._denominator);
}

Rational& Rational::operator=(const Rational other)
{
    this->_numerator = other.numerator();
    this->_denominator = other.denominator();
    return *this;
}
