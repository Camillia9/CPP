#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int nb_fixe;
	static const int nb_bits;
public:
	Fixed(); // Constructeur par defaut
	Fixed(const Fixed& arcp); // Constructeur de recopie
	Fixed& operator=(const Fixed& arcp); // Operations d'affectation
	~Fixed(); // Destructeur
	int getRawBits(void)const;
	void setRawBits(int const raw);
};

#endif