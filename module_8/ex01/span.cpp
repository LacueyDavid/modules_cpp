#include "span.hpp"
#include <limits>

Span::Span()
	: s()
	, capacity(0)
{}

Span::Span(std::size_t n)
	: s()
	, capacity(n)
{}

void Span::addNumber(int number)
{
	if (s.size() < capacity)
		s.insert(number);
	else
		throw std::exception();
}

int Span::longestSpan()
{
	if (s.size() < 2)
		throw std::exception();
	return *s.rbegin() - *s.begin();
}

int Span::shortestSpan()
{
	int x = std::numeric_limits<int>::max();

	for(std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		std::set<int>::iterator next = it;
		next++;
		if (next == s.end())
			break;
		if (*next - *it < x)
			x = *next - *it;
	}
	return x;
}
