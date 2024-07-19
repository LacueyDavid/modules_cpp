#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int toFind)
{
	return std::find(container.begin(), container.end(), toFind);
}

//typename parce que cest un type et le compilo devine pas
