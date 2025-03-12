#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
int main()
{
	{
		std::cout << "\033[32mTests from subject:\n\033[0m";
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout << "\nDeleting elements to prevent leaks. Thereby testing destruction:\n";
		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "\033[32m\n\n\nTesting copy construction:\n\033[0m";
		Dog Snoopy;
		std::cout << "\n";
		Dog Pluto(Snoopy);
		std::cout << "\nDestruction:\n";
	}
	{
		std::cout << "\033[32m\n\n\nTesting copy assignment:\n\033[0m";
		Cat Garfield;
		Garfield.makeSound();
		std::cout << "\n";
		Animal Foo;
		Foo.makeSound();
		std::cout << "\n";
		Foo = Garfield;
		Foo.makeSound();
		std::cout << "\nDestruction:\n";
	}

return 0;
}