#include "Fixed.hpp"

const int Fixed::nb_bits = 8;

Fixed::Fixed() : nb_fixe(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& arcp) : nb_fixe(arcp.nb_fixe) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& arcp) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &arcp)
		return *this;
	nb_fixe = arcp.nb_fixe;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
    return nb_fixe;
}

void Fixed::setRawBits(int const raw) {
    nb_fixe = raw;
}

Fixed::Fixed(const int value) {	// stock un nb entier
	std::cout << "Int constructor called" << std::endl;
	nb_fixe = value << nb_bits;
}

Fixed::Fixed(const float value) { // stcok un nb a virgule
	std::cout << "Float constructor called" << std::endl;
	nb_fixe = roundf(value * (1 << nb_bits));
					// (1 << nb_bits) = (1 << 8) = 256 
					// value * 256 convertit le float vers la representation a virgule fixe
					// rondf() sert a arrondir correctement.
}

float Fixed::toFloat(void)const {
	return (float)nb_fixe / (1 << nb_bits);
}

int Fixed::toInt(void)const {
	return nb_fixe >> nb_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}