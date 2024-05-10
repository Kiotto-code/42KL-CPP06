#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

struct Data {
    int value;
	std::string str;
};

class Serializer {
	private:
		Serializer(void);
		Serializer(Serializer const & src);
		~Serializer(void);
		// static Data *m_member;
	public:
		Serializer & operator = (const Serializer &src);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif