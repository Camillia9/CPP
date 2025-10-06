#include "Fixed.hpp"

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a.nb_fixe < b.nb_fixe)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a.nb_fixe < b.nb_fixe)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a.nb_fixe > b.nb_fixe)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a.nb_fixe > b.nb_fixe)
		return a;
	return b;
}