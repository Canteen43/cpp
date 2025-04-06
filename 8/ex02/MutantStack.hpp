#pragma once
#include <stack>
#include <deque>
template <typename Banana, typename Conty = std::deque<Banana> >
class MutantStack : public std::stack<Banana, Conty>
{
	public:
		typedef typename Conty::iterator iterator;
		iterator begin(); 
		iterator end();
};

#include "MutantStack.tpp"