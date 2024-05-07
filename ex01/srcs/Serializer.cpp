#include <iostream>
#include <cstdint>
#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "[Serializer] default constructor was being called" << std::endl;
}

Serializer::Serializer(Serializer const &src)
{
	std::cout << "[Serializer] copy constructor was being called" << std::endl;
	// *this = src;
	(void)src;
}

Serializer::~Serializer(void)
{
	std::cout << "[Serializer] destructor was being called" << std::endl;
}

Serializer	&Serializer::operator = (const Serializer &src)
{
	std::cout << "assdignment operator was being called" << std::endl;
	return (*this);
	(void)src;
}

uintptr_t Serializer::serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }
Data* Serializer::deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }

int main()
{
	// Serializer s = Serializer();
	Data data;
	Data* dataPtr;
	uintptr_t raw;

	data.str = "test_data";
	data.value = 42;
	std::cout << &data << std::endl;
	std::cout << data.str << std::endl;
	std::cout << data.value << std::endl;

	raw = Serializer::serialize(&data);
	std::cout << "rawadd value:" << raw << std::endl;

	dataPtr = Serializer::deserialize(raw);
	std::cout << dataPtr << std::endl;
	std::cout << dataPtr->str << std::endl;
	std::cout << dataPtr->value << std::endl;
}
