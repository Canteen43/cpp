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
		template <typename iterator>
		void addRange(unsigned int rangeSize, iterator begin, iterator end)
		{
			if (bucket.size() + rangeSize > capacity)
				throw std::runtime_error("Range would exceed capacity.");
			bucket.insert(begin, end);
		}
		int shortestSpan();
		int longestSpan();
};