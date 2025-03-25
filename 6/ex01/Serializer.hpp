#pragma once
#include <string>

typedef unsigned long long uintptr_t;

struct Data
{
	double latitude;
	double longitude;
	std::string motto;
};

class Serializer
{
	private:
		Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};