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