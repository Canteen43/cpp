#pragma once
#include <cstddef>
#include <stdexcept>
template <typename banana>
class Array
{
	private:
		unsigned int length;
		banana *arr;
	public:
		Array();
		Array(unsigned int n); 
		Array(Array& other);
		~Array();
		Array& operator=(Array& other);
		banana& operator[](int index);
		unsigned int size();
};

template <typename banana>
Array<banana>::Array()
: length(0), arr(NULL)
{};
template <typename banana>
Array<banana>::Array(unsigned int n)
: length(n)
{
	arr = new banana[length]();
}; 
template <typename banana>
Array<banana>::Array(Array& other)
{
	length = other.length;
	arr = new banana[length]();
	for (unsigned int i = 0; i < length; i++)
	{
		arr[i] = other.arr[i];
	}
};
template <typename banana>
Array<banana>::~Array()
{
		delete[] arr;
};
template <typename banana>
Array<banana>& Array<banana>::operator=(Array& other)
{
	if (this == &other)
		return *this;
	length = other.length;
	delete arr;
	arr = new banana[length]();
	for (unsigned int i = 0; i < length; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
};
template <typename banana>
banana& Array<banana>::operator[](int index)
{
	if (index < 0 || index >= (int)length)
		throw std::exception();
	return arr[index];
};
template <typename banana>
unsigned int Array<banana>::size()
{
	return length;
};