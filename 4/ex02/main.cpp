#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>
int main()
{
	
	{
		std::cout << "\033[32mBrain class, Copy constructor:\n\033[0m";
		Brain myBrain;
		myBrain.setIdea(69, "you know what");
		std::cout << myBrain.getIdea(69) << "\n";
		Brain yourBrain(myBrain);
		std::cout << yourBrain.getIdea(69) << "\n";
	}
	{
		std::cout << "\n\033[32mBrain class, Copy assigment operator:\n\033[0m";
		Brain myBrain;
		Brain yourBrain;
		myBrain.setIdea(69, "you know what");
		std::cout << myBrain.getIdea(69) << "\n";
		yourBrain = myBrain;
		std::cout << yourBrain.getIdea(69) << "\n";
	}
	{
		std::cout << "\n\033[32mCat class (=Dog class), Copy constructor:\n\033[0m";
		Cat Garfield;
		Garfield.setIdea(1, "I hate mondays");
		std::cout << Garfield.getIdea(1) << "\n";
		Cat Catwoman(Garfield);
		std::cout << Catwoman.getIdea(1) << "\n";
	}
	{
		std::cout << "\n\033[32mCat class (=Dog class), Copy assignment operator:\n\033[0m";
		Cat Garfield;
		Garfield.setIdea(1, "I hate mondays");
		std::cout << Garfield.getIdea(1) << "\n";
		Cat Catwoman;
		Catwoman = Garfield;
		std::cout << Catwoman.getIdea(1) << "\n";
	}
	{
		std::cout << "\n\033[32mTests from subject:\n\033[0m";
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	{
		// In your main function, create and fill an array of Animal objects. Half of it will
		// be Dog objects and the other half will be Cat objects. At the end of your program
		// execution, loop over this array and delete every Animal. You must delete directly dogs
		// and cats as Animals. The appropriate destructors must be called in the expected order.
		std::cout << "\n\033[32mAnimal array:\n\033[0m";
		std::cout << "\033[32mCreation and filling:\n\033[0m";
		int farmsize = 6;
		Animal *farm[farmsize];
		for (int i = 0; i < farmsize; i++)
		{
			if (i % 2)
				farm[i] = new Cat;
			else
				farm[i] = new Dog;
			farm[i]->makeSound();
		}
		std::cout << "\033[32mDeletion:\n\033[0m";
		for (int i = 0; i < farmsize; i++)
		{
			delete farm[i];
		}
	}
	return 0;
}