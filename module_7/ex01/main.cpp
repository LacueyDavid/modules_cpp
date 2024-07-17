#include "iter.hpp"

int main()
{
	int array[] = {1,2,3,4,5};
	for (std::size_t i = 0; i < 5; ++i)
		std::cout << array[i] << "\n";
	::iter(array, 5, double_it<int>);
	for (std::size_t i = 0; i < 5; ++i)
		std::cout << array[i] << "\n";
	::iter(array, 5, divide_it<int>);
	::iter(array, 5, is_odd<int>);
}
