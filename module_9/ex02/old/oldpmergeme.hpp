#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <climits>
#include <cstdlib>
#include <ctime>   // For clock_t, clock, CLOCKS_PER_SEC
#include <deque>
#include <iostream>
#include <sstream> // For std::stringstream
#include <vector>

#define RED "\033[31m"
#define RESET "\033[0m"

class PmergeMe
{
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();

	private:
		std::deque<int>					_deque;
		std::vector<int>				_vector;

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe						&operator=(const PmergeMe &other);


		void							checkArguments(int ac, char **av);
		void							printArray(int ac, char **av);
		void 							printElapsedTime(int elements, double elapsed_secs, bool vector);

		// Vector
		void							insertArgumentsIntoVector(int ac, char **av);
		std::vector<int>				fordJohnsonSortVector(std::vector<int> &vector);
		void							insert(std::vector<int> &high, std::vector<int> &low);
		void							insertRemainder(std::vector<int> &vector, int n);
		int 							binary_search_insert_position(const std::vector<int> &vector, int n);
		std::vector<int>				generateInsertionOrderVector(int n);
		std::vector<int>				generateJacobsthalSequenceVector(int n);
		void							printVector();

		// Deque
		void							insertArgumentsIntoDeque(int ac, char **av);
		std::deque<int>					fordJohnsonSortDeque(std::deque<int> &deque);
		void							insert(std::deque<int> &high, std::deque<int> &low);
		void							insertRemainder(std::deque<int> &deque, int n);
		int 							binary_search_insert_position(const std::deque<int> &deque, int n);
		std::deque<int>					generateInsertionOrderDeque(int n);
		std::deque<int>					generateJacobsthalSequenceDeque(int n);
		void							printDeque();
};

#endif