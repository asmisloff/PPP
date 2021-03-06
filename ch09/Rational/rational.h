#pragma once
#include <iostream>
#include <string>

class Rational {
public:
    Rational() : _numerator(0), _denominator(1) {}
    Rational(int num, int den);
    int numerator() const {return _numerator;}
    int denominator()const {return _denominator;}
    int integer_part() const {return _numerator / _denominator; }
    std::string to_string() const { return std::to_string(_numerator) + '/' + std::to_string(_denominator); }
    std::string normalized() const;
    
    friend const Rational operator+(const Rational& left, const Rational& right);
    friend const Rational operator-(const Rational& left, const Rational& right);
    friend const Rational operator*(const Rational& left, const Rational& right);
    friend const Rational operator/(const Rational& left, const Rational& right);
    friend bool operator==(const Rational& left, const Rational& right);
    Rational& operator=(const Rational other);
    
private:
    int _numerator;
    int _denominator;
    
	const Rational& reduce();
};

std::ostream& operator<<(std::ostream& out, const Rational& r);
