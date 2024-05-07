/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:55:23 by yichan            #+#    #+#             */
/*   Updated: 2024/05/07 22:55:57 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint>
#include "Color.hpp"
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
	std::cout << "Class_addr\t:"GOLD << &data << RESET << std::endl;
	// std::cout << data.str << std::endl;
	// std::cout << data.value << std::endl;

	raw = Serializer::serialize(&data);
	std::cout << "serialize\t:" << raw << std::endl;

	dataPtr = Serializer::deserialize(raw);
	std::cout << "deserialize\t:"GOLD << dataPtr << RESET << std::endl;
	std::cout << dataPtr->str << std::endl;
	std::cout << dataPtr->value << std::endl;
}

/* <uintptr_t>: This is the type you're casting to. uintptr_t
	is an unsigned integer type defined in <cstdint> (or <stdint.h> in C), 
	which is guaranteed to be large enough to hold any pointer. 
	It's typically used for casting pointers to integers without loss of information.*/
