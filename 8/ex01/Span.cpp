#include "Span.hpp"
Span::Span()
: capacity(0)
{};
Span::Span(unsigned int N)
: capacity(N)
{};
Span::Span(const Span& other)
: capacity(other.capacity)
{
	bucket = other.bucket;
};
Span& Span::operator=(const Span& other)
{
	capacity = other.capacity;
	bucket = other.bucket;
	return *this;
};
Span::~Span()
{};
void Span::addNumber(int newNumber)
{
	if (bucket.size() == capacity)
		throw std::runtime_error("Span is full.");
	bucket.insert(newNumber);
};
int Span::shortestSpan()
{
	if (bucket.size() < 2)
		throw std::runtime_error("Span has less than two values.");

	std::set<int>::iterator it1 = bucket.begin();
	std::set<int>::iterator it2 = it1;
	++it2;
	int result = *it2 - *it1;
	for (; it2 != bucket.end(); ++it1, ++it2)
	{
		result = std::min(result, *it2 - *it1);
	}
	return result;
};
int Span::longestSpan()
{
	if (bucket.size() < 2)
		throw std::runtime_error("Span has less than two values.");
	std::multiset<int>::iterator last = bucket.end();
	last--;
	return *last - *bucket.begin();
};