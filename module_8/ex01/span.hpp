#ifndef SPAN_HPP
# define SPAN_HPP

#include <set>

class Span
{
public:
	Span();
	Span(std::size_t n);
	void addNumber(int number);
	int shortestSpan();
	int longestSpan();
	template <typename It>
	void addNumber(It first, It last);
private:
	std::set<int> s;
	std::size_t capacity;
};

template <typename It>
void Span::addNumber(It first, It last)
{
	for (It i = first; i != last; ++i)
		addNumber(*i);
}

#endif
