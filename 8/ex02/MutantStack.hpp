#pragma once
#include <stack>
class MutantStack : public std::stack
{

};

/*Ideas:
The stack has a member variable container.
Its functions are all implemented using the functions of the base container.
The container is only 'protected' so that MutantStack can still access it.
Questions:
1) Do I really need rend, rbegin and all the const stuff?
2) What is the syntax for writing this kind of stuff? */

#include "MutantStack.tpp"