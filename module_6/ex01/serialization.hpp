#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>

struct Data
{
	int x;
	int y;
};

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
private:
	Serializer();
};

#endif
