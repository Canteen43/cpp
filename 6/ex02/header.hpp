#pragma once
#include <ctime>	//for std::time()
#include <iostream>
class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

// It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
Base * generate(void);
// It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base* p);
// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.
void identify(Base& p);