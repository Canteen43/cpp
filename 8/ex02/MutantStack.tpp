#include "MutantStack.hpp"
template <typename Banana, typename Conty>
typename MutantStack<Banana, Conty>::iterator MutantStack<Banana, Conty>::begin()
{
	return this->c.begin();
};
template <typename Banana, typename Conty>
typename MutantStack<Banana, Conty>::iterator MutantStack<Banana, Conty>::end()
{
	return this->c.end();
};