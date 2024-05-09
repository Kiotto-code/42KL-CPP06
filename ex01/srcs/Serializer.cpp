/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:55:23 by yichan            #+#    #+#             */
/*   Updated: 2024/05/09 16:08:18 by yichan           ###   ########.fr       */
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

// Pointer Serialization: Serializing a pointer means converting it into a format that can be stored or transmitted, often as a sequence of bytes. This can be useful for scenarios such as saving the state of an application to disk, sending data over a network, or implementing inter-process communication.
// Platform Dependency: The uintptr_t type is an integer type guaranteed to be able to hold a pointer value without loss of information. However, it's important to note that the size and representation of pointers can vary between different platforms and architectures. Therefore, serializing a pointer address to uintptr_t may not be portable across different systems.
// Lifetime Management: When serializing a pointer address, you're essentially capturing the memory location of an object. This can be problematic if the object pointed to by the serialized address is deallocated or moved in memory before the serialized address is deserialized and used. This can lead to undefined behavior, crashes, or security vulnerabilities if not carefully managed.
// Security Implications: Serializing pointer addresses can potentially expose sensitive information about the memory layout of a program, which could be exploited by attackers for memory manipulation or other security vulnerabilities. Therefore, it's important to consider the security implications of serializing pointer addresses, especially in systems where security is a concern.
