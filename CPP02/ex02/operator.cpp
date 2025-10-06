#include "Fixed.hpp"

bool Fixed::operator>(const Fixed& other)const {
	return nb_fixe > other.nb_fixe;
}

bool Fixed::operator<(const Fixed& other)const {
	return nb_fixe < other.nb_fixe;
}

bool Fixed::operator>=(const Fixed& other)const {
	return nb_fixe >= other.nb_fixe;
}

bool Fixed::operator<=(const Fixed& other)const {
	return nb_fixe <= other.nb_fixe;
}

bool Fixed::operator==(const Fixed& other)const {
	return nb_fixe == other.nb_fixe;
}

bool Fixed::operator!=(const Fixed& other)const {
	return nb_fixe != other.nb_fixe;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.nb_fixe = nb_fixe + other.nb_fixe;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.nb_fixe = nb_fixe - other.nb_fixe;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.nb_fixe = (nb_fixe * other.nb_fixe) >> nb_bits; //Divise par 256
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.nb_fixe = (nb_fixe / other.nb_fixe) << nb_bits; //Multiplie par 256
	return result;
}

Fixed& Fixed::operator++() { // Pré-incrémentation (++a)
	nb_fixe++;
	return *this;
}

Fixed Fixed::operator++(int) { // Post-incrémentation (a++)
	Fixed tmp(*this);
	nb_fixe++;
	return tmp;
}

Fixed& Fixed::operator--() { // Pré-décrémentation (--a)
	nb_fixe--;
	return *this;
}

Fixed Fixed::operator--(int) { // Post-décrémentation (a--)
	Fixed tmp(*this);
	nb_fixe--;
	return tmp;
}