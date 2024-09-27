#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe) { (void)pmergeMe; }

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe)
{
	(void)pmergeMe;
	return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av)
	: ac(ac)
	, av(av)
	, _elapsed_time_vector(0.0)
	, _elapsed_time_deque(0.0)
{}

void PmergeMe::execute()
{
	try
	{
		checkArguments();
		printArray();
		startSortingVector();
		startSortingDeque();
		printVector();
		printElapsedTimes();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << "\n";
		return;
	}
}

void PmergeMe::checkArguments()
{
	if (ac < 2)
		throw std::invalid_argument("Usage: ./pmergeme [integers]");
	for (int i = 1; i < ac; ++i)
	{
		char *end;
		long number = std::strtol(av[i], &end, 10);
		if (*end != '\0')
			throw std::invalid_argument("Error, neg: " + std::string(av[i]));
		if (number < 0 || number > INT_MAX)
			throw std::invalid_argument("Num to big: " + std::string(av[i]));
	}
}

void PmergeMe::printArray()
{
	std::cout << "Before: ";
	for (int i = 1; i < ac; ++i)
		std::cout << av[i] << " ";
	std::cout << "\n";
}

void PmergeMe::printVector()
{
	std::cout << "After: ";
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}

void PmergeMe::printElapsedTimes()
{
	printElapsedTime("std::vector", _vector.size(), _elapsed_time_vector);
	printElapsedTime("std::deque", _deque.size(), _elapsed_time_deque);
}

void PmergeMe::printElapsedTime(const std::string &container_name, size_t size,
				double elapsed_time)
{
	std::cout << "Time to process a range of " << size << " elements with "
	<< container_name << ": ";

	if (elapsed_time == 0.0)
		std::cout << "not sorted\n";
	else if (elapsed_time >= 1.0)
		std::cout << elapsed_time << " seconds\n";
	else if (elapsed_time >= 1e-3)
		std::cout << elapsed_time * 1e3 << " milliseconds\n";
	else if (elapsed_time >= 1e-6)
		std::cout << elapsed_time * 1e6 << " microseconds\n";
	else
		std::cout << elapsed_time * 1e9 << " nanoseconds\n";
}

void PmergeMe::startSortingVector()
{
	clock_t start_time_vector = clock();
	fillVector();
	_vector = mergeInsertSortVector(_vector);
	_elapsed_time_vector = double(std::clock() - start_time_vector) / CLOCKS_PER_SEC;
}

void PmergeMe::fillVector()
{
	for (int i = 1; i < ac; ++i)
	{
		char *end;
		long number = std::strtol(av[i], &end, 10);
		_vector.push_back(static_cast<int>(number));
	}
}

std::vector<int> PmergeMe::mergeInsertSortVector(std::vector<int> &vector)
{
	if (vector.size() <= 1)
		return vector;

	std::vector<int> main, pend;
	int remainder = -1;

	if (vectorIsOdd(vector))
		remainder = setRemainderVector(vector);

	createPair(main, pend, vector);
	main = mergeInsertSortVector(main);
	insert(main, pend);
	insertRemainder(main, remainder);

	return main;
}

bool PmergeMe::vectorIsOdd(const std::vector<int> &vector)
{
	return vector.size() % 2;
}

int PmergeMe::setRemainderVector(std::vector<int> &vector)
{
	int remainder = vector.back();
	vector.pop_back();
	return remainder;
}

void PmergeMe::createPair(std::vector<int> &main, std::vector<int> &pend
						  , const std::vector<int> &vector)
{
	for (size_t i = 0; i < vector.size(); i += 2)
	{
		main.push_back(std::max(vector[i], vector[i + 1]));
		pend.push_back(std::min(vector[i], vector[i + 1]));
	}
}

void PmergeMe::insert(std::vector<int> &main, std::vector<int> &pend)
{
	std::vector<int> insertion_order = generateInsertionOrderVector(pend.size());
	for (size_t i = 0; i < insertion_order.size(); ++i)
	{
		int pos = binary_search_insert_position(main, pend[insertion_order[i]]);
		main.insert(main.begin() + pos, pend[insertion_order[i]]);
	}
}

std::vector<int> PmergeMe::generateInsertionOrderVector(int pendSize)
{
	std::vector<int> jacobsthal_sequence = generateJacobsthalSequenceVector(pendSize);
	std::vector<int> insertion_order;
	if (jacobsthal_sequence.empty())
		return insertion_order;
	for (size_t i = 1; i < jacobsthal_sequence.size(); ++i)
	{
		int current = jacobsthal_sequence[i];
		int previous = jacobsthal_sequence[i - 1];
		for (int j = current; j > previous; --j)
			if (j <= pendSize)
				insertion_order.push_back(j - 1);
	}
	return insertion_order;
}

std::vector<int> PmergeMe::generateJacobsthalSequenceVector(int pendSize)
{
	std::vector<int> jacobsthal_sequence;
	int i = 2;
	int next;

	jacobsthal_sequence.push_back(0);
	jacobsthal_sequence.push_back(1);
	while (true)
	{
		next = jacobsthal_sequence[i - 1] + 2 * jacobsthal_sequence[i - 2];
		jacobsthal_sequence.push_back(next);
		++i;
		if (next >= pendSize)
			break;
	}
	return jacobsthal_sequence;
}

void PmergeMe::insertRemainder(std::vector<int> &main, int remainder)
{
	if (remainder != -1)
	{
		int pos = binary_search_insert_position(main, remainder);
		main.insert(main.begin() + pos, remainder);
	}
}

int PmergeMe::binary_search_insert_position(const std::vector<int> &vector, int value)
{
	int left = 0;
	int right = vector.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (vector[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

///////////////// DEQUE //////////////

void PmergeMe::startSortingDeque()
{
	clock_t start_time_deque = clock();
	fillDeque();
	_deque = mergeInsertSortDeque(_deque);
	_elapsed_time_deque = double(std::clock() - start_time_deque) / CLOCKS_PER_SEC;
}

void PmergeMe::fillDeque()
{
	for (int i = 1; i < ac; ++i)
	{
		char *end;
		long number = std::strtol(av[i], &end, 10);
		_deque.push_back(static_cast<int>(number));
	}
}

std::deque<int> PmergeMe::mergeInsertSortDeque(std::deque<int> &deque)
{
	if (deque.size() <= 1)
		return deque;

	std::deque<int> main, pend;
	int remainder = -1;

	if (dequeIsOdd(deque))
		remainder = setRemainderDeque(deque);

	createPair(main, pend, deque);
	main = mergeInsertSortDeque(main);
	insert(main, pend);
	insertRemainder(main, remainder);

	return main;
}

void PmergeMe::insert(std::deque<int> &main, std::deque<int> &pend)
{
	std::deque<int> insertion_order = generateInsertionOrderDeque(pend.size());
	for (size_t i = 0; i < insertion_order.size(); ++i)
	{
		int pos = binary_search_insert_position(main, pend[insertion_order[i]]);
		main.insert(main.begin() + pos, pend[insertion_order[i]]);
	}
}

void PmergeMe::insertRemainder(std::deque<int> &main, int remainder)
{
	if (remainder != -1)
	{
		int pos = binary_search_insert_position(main, remainder);
		main.insert(main.begin() + pos, remainder);
	}
}

int PmergeMe::binary_search_insert_position(const std::deque<int> &deque, int value)
{
	int left = 0;
	int right = deque.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (deque[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

std::deque<int> PmergeMe::generateInsertionOrderDeque(int pendSize)
{
	std::deque<int> jacobsthal_sequence = generateJacobsthalSequenceDeque(pendSize);
	std::deque<int> insertion_order;
	if (jacobsthal_sequence.empty())
		return insertion_order;
	for (size_t i = 1; i < jacobsthal_sequence.size(); ++i)
	{
		int current = jacobsthal_sequence[i];
		int previous = jacobsthal_sequence[i - 1];
		for (int j = current; j > previous; --j)
			if (j <= pendSize)
				insertion_order.push_back(j - 1);
	}
	return insertion_order;
}

std::deque<int> PmergeMe::generateJacobsthalSequenceDeque(int pendSize)
{
	std::deque<int> jacobsthal_sequence;
	int i = 2;
	int next;

	jacobsthal_sequence.push_back(0);
	jacobsthal_sequence.push_back(1);
	while (true)
	{
		next = jacobsthal_sequence[i - 1] + 2 * jacobsthal_sequence[i - 2];
		jacobsthal_sequence.push_back(next);
		++i;
		if (next >= pendSize)
			break;
	}
	return jacobsthal_sequence;
}

void PmergeMe::createPair(std::deque<int> &main, std::deque<int> &pend
						  , const std::deque<int> &deque)
{
	for (size_t i = 0; i < deque.size(); i += 2)
	{
		main.push_back(std::max(deque[i], deque[i + 1]));
		pend.push_back(std::min(deque[i], deque[i + 1]));
	}
}

bool PmergeMe::dequeIsOdd(const std::deque<int> &deque)
{
	return deque.size() % 2;
}

int PmergeMe::setRemainderDeque(std::deque<int> &deque)
{
	int remainder = deque.back();
	deque.pop_back();
	return remainder;
}

// tests

void PmergeMe::executeTests()
{
	try
	{
		testIsVectorSorted();
		testIsDequeSorted();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << "\n";
		return;
	}
}

void PmergeMe::testIsVectorSorted()
{
	std::cout << "testIsVectorSorted... ";
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		if (it != _vector.begin() && *it < *(it - 1))
			throw std::logic_error("Vector not sorted");
	}
	std::cout << "the vector is correctly sorted! :D\n";
}

void PmergeMe::testIsDequeSorted()
{
	std::cout << "testIsDequeSorted... ";
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it)
	{
		if (it != _deque.begin() && *it < *(it - 1))
			throw std::logic_error("Deque not sorted");
	}
	std::cout << "the deque is correctly sorted! :D\n";
}
