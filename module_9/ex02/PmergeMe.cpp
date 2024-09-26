#include "PmergeMe.hpp"

// canonique forme

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe) { (void)pmergeMe; }

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe)
{
	(void)pmergeMe;
	return *this;
}

PmergeMe::~PmergeMe() {}

// public

PmergeMe::PmergeMe(int ac, char **av) { (void)ac; (void)av; }

void PmergeMe::execute() { std::cout << "execute" << std::endl; }
