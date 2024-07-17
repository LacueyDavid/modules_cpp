#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <class T>
class Array
{
public:
	Array();
	~Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(Array other);
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	void swap(Array& other);
	std::size_t size();
private:
	T *data;
	std::size_t arraySize;
};

template <class T>
Array<T>::Array()
	: data(0)
	, arraySize(0)
{}


template <class T>
Array<T>::~Array()
{
	delete[] data;
}

template <class T>
Array<T>::Array(unsigned int n)
	: data(new T[n]())
	, arraySize(n)
{}

template <class T>
Array<T>::Array(const Array& other)
	: data(new T[other.arraySize]())
	, arraySize(other.arraySize)
{
	for (std::size_t i = 0; i < arraySize; ++i)
		data[i] = other.data[i];
}

template <class T>
Array<T>& Array<T>::operator=(Array other)
{
	this->swap(other);
	return *this;
}

template <class T>
T& Array<T>::operator[](std::size_t index)
{
	if (index >= arraySize)
		throw std::exception();
	return data[index];
}

template <class T>
const T& Array<T>::operator[](std::size_t index) const
{
	if (index >= arraySize)
		throw std::exception();
	return data[index];
}

template <class T>
void Array<T>::swap(Array& other)
{
	swap(data, other.data);
	swap(arraySize, other.arraySize);
}

template <class T>
std::size_t Array<T>::size()
{
	return arraySize;
}

// rules of three, destructeur, constructeur par copy , copy assign.
// si on a besoin de faire un truc intelligent dans l'un des trois, alors
// faudra faire gaffe aux 2 autres
#endif
