#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <climits>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

class PmergeMe
{

public:
	PmergeMe(int ac, char **av);
	~PmergeMe();
	void execute();

private:
	PmergeMe();
	PmergeMe(const PmergeMe &pmergeMe);
	PmergeMe &operator=(const PmergeMe &pmergeMe);
};

#endif
