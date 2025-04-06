#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include "MutantStack.hpp"

int main()
{
	std::cout << "\033[4mTests from subject\033[0m\n";
	{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	}

	std::cout << "\n\033[4mTests from subject with std::list\033[0m\n";
	{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int, std::list<int> > s(mstack);
	}

	std::cout << "\n\033[4mMy own tests\033[0m\n";
	{
	MutantStack<std::string, std::vector<std::string> > crazyStack;
	std::ostringstream oss;
	for (int i = 0; i < 5; ++i)
	{
		oss.str("");
		oss << i;	
		crazyStack.push(oss.str());
	}
	for (MutantStack<std::string, std::vector<std::string> >::iterator it = crazyStack.begin(); it != crazyStack.end(); ++it)
		std::cout << *it << "\n";
	}
	
	
	return 0;
}