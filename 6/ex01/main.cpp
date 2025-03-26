#include <iostream>
#include "Serializer.hpp"
int main()
{
	Data fortyTwoNeukoelln;
	fortyTwoNeukoelln.latitude = 52.484453339301204;
	fortyTwoNeukoelln.longitude = 13.449772146694569;
	fortyTwoNeukoelln.motto = "Whenever something is done badly, we will claim it is on purpose to facilitate your personal growth :)\n";
	std::cout << &fortyTwoNeukoelln << "\n";
	uintptr_t foo = Serializer::serialize(&fortyTwoNeukoelln);
	std::cout << foo << "\n";
	Data *bar = Serializer::deserialize(foo);
	std::cout << bar->latitude << ", " << bar->longitude << ": " << bar->motto;
}