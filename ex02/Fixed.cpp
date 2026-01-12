#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {}
Fixed::Fixed(const int intVal) {this->_fixedPointValue = intVal << _fractionalBits;}
Fixed::Fixed(const float floatVal) {this->_fixedPointValue = roundf(floatVal * (1 << _fractionalBits));}
Fixed::Fixed(const Fixed &other) {*this = other;}
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) this->_fixedPointValue = other.getRawBits();
    return *this;
}
Fixed::~Fixed() {}
int Fixed::getRawBits(void) const { return this->_fixedPointValue; }
void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }
float Fixed::toFloat(void) const { return (float)this->_fixedPointValue / (1 << _fractionalBits); }
int Fixed::toInt(void) const { return this->_fixedPointValue >> _fractionalBits; }

bool Fixed::operator>(const Fixed &other) const { return this->_fixedPointValue > other._fixedPointValue; }
bool Fixed::operator<(const Fixed &other) const { return this->_fixedPointValue < other._fixedPointValue; }
bool Fixed::operator>=(const Fixed &other) const { return this->_fixedPointValue >= other._fixedPointValue; }
bool Fixed::operator<=(const Fixed &other) const { return this->_fixedPointValue <= other._fixedPointValue; }
bool Fixed::operator==(const Fixed &other) const { return this->_fixedPointValue == other._fixedPointValue; }
bool Fixed::operator!=(const Fixed &other) const { return this->_fixedPointValue != other._fixedPointValue; }

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    long long temp = (long long)this->_fixedPointValue * (long long)other.getRawBits();
    result.setRawBits(temp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    long long temp = ((long long)this->_fixedPointValue << _fractionalBits) / other.getRawBits();
    result.setRawBits(temp);
    return result;
}

Fixed &Fixed::operator++() {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--() {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_fixedPointValue--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}