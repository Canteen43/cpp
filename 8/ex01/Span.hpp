#pragma once
#include <set>
#include <stdexcept>
#include <iterator> //std::next()
class Span
{
	private:
		unsigned int capacity;
		std::multiset<int> bucket;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int newNumber);
		int shortestSpan();
		int longestSpan();
};