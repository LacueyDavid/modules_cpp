#include "span.hpp"
#include "iostream"
#include <vector>

int main()
{
	Span span(17342);
	std::vector<int> v;
	for (int i = 0; i < 17342; i++)
		v.push_back(i);
	try
	{
		span.addNumber(4);
	}
	catch (const std::exception& e)
	{
		std::cout << "can't add more elements\n";
	}
	span.addNumber(v.begin(), v.end());
	std::cout << span.shortestSpan() << "\n";
	std::cout << span.longestSpan() << "\n";
}
