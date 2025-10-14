#include "Serialization.hpp"

Serialization::Serialization() {
	std::cout << "Default constructor Serialization is called" << std::endl;
}

Serialization::Serialization(const Serialization& other) {
	(void)other;
}

Serialization& Serialization::operator=(const Serialization& other) {
	(void)other;
	return *this;
}

Serialization::~Serialization() {
	std::cout << "Destructor Serialization is called" << std::endl;
}

uintptr_t Serialization::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialization::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

