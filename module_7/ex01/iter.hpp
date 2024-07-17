#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, std::size_t length, F f)
{
	if (length == 0 || !array || !f)
		return;
	for (std::size_t i = 0; i < length; ++i)
	{
		f(array[i]);
	}
}

template <typename T>
void double_it(T& x)
{
	x *= 2;
}

template <typename T>
void divide_it(T& x)
{
	x /= 2;
}

template <typename T>
void is_odd(T& x)
{
	if(x % 2 != 0)
		std::cout << "i'm odd baby!\n";
}

#endif
