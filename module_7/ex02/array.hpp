#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>

template <class T>
class Array
{
public:
	Array();
	~Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(Array other);
	void swap(Array& other);
private:
	T *data;
	std::size_t size;
};

template <class T>
Array<T>::Array()
	: data(0)
	, size(0)
{}


template <class T>
Array<T>::~Array()
{
	delete[] data;
}

template <class T>
Array<T>::Array(unsigned int n)
	: data(new T[n]())
	, size(n)
{}

template <class T>
Array<T>::Array(const Array& other)
	: data(new T[other.size]())
	, size(other.size)
{
	for (std::size_t i = 0; i < size; ++i)
		data[i] = other.data[i];
}

template <class T>
Array<T>& Array<T>::operator=(Array other)
{
	this->swap(other);
	return *this;
}

template <class T>
void Array<T>::swap(Array& other)
{
	swap(data, other.data);
	swap(size, other.size);
}

// rules of three, destructeur, constructeur par copy , copy assign.
// si on a besoin de faire un truc intelligent dans l'un des trois, alors
// faudra faire gaffe aux 2 autres
#endif
