#include "PmergeMe.hpp"

#define VECTOR true
#define DEQUE false

PmergeMe::PmergeMe(int ac, char **av)
{
	try
	{
		checkArguments(ac, av);
		printArray(ac, av);

		clock_t start_vector = clock();
		insertArgumentsIntoVector(ac, av);
		_vector = fordJohnsonSortVector(_vector);
		double elapsed_secs_vector = double(std::clock() - start_vector) / CLOCKS_PER_SEC;
		printVector();

		clock_t start_deque = clock();
		insertArgumentsIntoDeque(ac, av);
		_deque = fordJohnsonSortDeque(_deque);
		double elapsed_secs_deque = double(std::clock() - start_deque) / CLOCKS_PER_SEC;
		// printDeque();

		printElapsedTime(_vector.size(), elapsed_secs_vector, VECTOR);
		printElapsedTime(_deque.size(), elapsed_secs_deque, DEQUE);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

std::vector<int>	PmergeMe::generateInsertionOrderVector(int n)
{
	std::vector<int>	jacobsthal_sequence = generateJacobsthalSequenceVector(n);
	std::vector<int>	insertion_order;

	if (jacobsthal_sequence.empty())
	{
		return insertion_order;
	}

	for (size_t i = 1; i < jacobsthal_sequence.size(); ++i)
	{
		int k = jacobsthal_sequence[i];

		while (k > jacobsthal_sequence[i - 1])
		{
			if (k <= n)
				insertion_order.push_back(k - 1);
			--k;
		}
	}

	return insertion_order;
}

std::vector<int> PmergeMe::generateJacobsthalSequenceVector(int n)
{
	std::vector<int>	jacobsthal_sequence;
	int					i = 2;
	int					next;

	jacobsthal_sequence.push_back(0);
	jacobsthal_sequence.push_back(1);
	while (true)
	{
		next = jacobsthal_sequence[i - 1] + 2 * jacobsthal_sequence[i - 2];
		jacobsthal_sequence.push_back(next);
		++i;
		if (next >= n)
			break;
	}

	return jacobsthal_sequence;
}

int PmergeMe::binary_search_insert_position(const std::vector<int> &vector, int n)
{
	int low = 0;
	int high = vector.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (vector[mid] < n) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return low;
}

void	PmergeMe::insert(std::vector<int> &high, std::vector<int> &low)
{
	std::vector<int>	insertion_order = generateInsertionOrderVector(low.size());

	for (size_t i = 0; i < insertion_order.size(); ++i)
	{
		int	n = insertion_order[i];
		int	pos = binary_search_insert_position(high, low[n]);

		high.insert(high.begin() + pos, low[n]);
	}
}

void	PmergeMe::insertRemainder(std::vector<int> &vector, int n)
{
	if (n != -1)
	{
		int pos = binary_search_insert_position(vector, n);
		vector.insert(vector.begin() + pos, n);
	}
}

std::vector<int>	PmergeMe::fordJohnsonSortVector(std::vector<int> &vector)
{
	std::vector<int>	low, high;
	int					remainder = -1;

	if (vector.size() == 1)
		return vector;

	if (vector.size() % 2 == 1)
	{
		remainder = vector.back();
		vector.pop_back();
	}

	for (size_t i = 0; i < vector.size(); i += 2)
	{
		low.push_back(std::min(vector[i], vector[i + 1]));
		high.push_back(std::max(vector[i], vector[i + 1]));
	}

	high = fordJohnsonSortVector(high);
	insert(high, low);
	insertRemainder(high, remainder);

	return high;
}

void	PmergeMe::insertArgumentsIntoVector(int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		char* end;
		long number = std::strtol(av[i], &end, 10);
		_vector.push_back(static_cast<int>(number));
	}
}

void	PmergeMe::printVector()
{
	std::cout << "Sorted vector: ";
	for (size_t i = 0; i < _vector.size(); ++i)
	{
		std::cout << _vector[i] << " ";
		if (i > 0 && _vector[i] < _vector[i - 1])
		{
			std::cout << "Vector not sorted";
			break;
		}
	}
	std::cout << std::endl;
}

std::deque<int>	PmergeMe::generateInsertionOrderDeque(int n)
{
	std::deque<int>	jacobsthal_sequence = generateJacobsthalSequenceDeque(n);
	std::deque<int>	insertion_order;

	if (jacobsthal_sequence.empty())
	{
		return insertion_order;
	}

	for (size_t i = 1; i < jacobsthal_sequence.size(); ++i)
	{
		int k = jacobsthal_sequence[i];

		while (k > jacobsthal_sequence[i - 1])
		{
			if (k <= n)
				insertion_order.push_back(k - 1);
			--k;
		}
	}

	return insertion_order;
}

std::deque<int> PmergeMe::generateJacobsthalSequenceDeque(int n)
{
	std::deque<int>	jacobsthal_sequence;
	int					i = 2;
	int					next;

	jacobsthal_sequence.push_back(0);
	jacobsthal_sequence.push_back(1);
	while (true)
	{
		next = jacobsthal_sequence[i - 1] + 2 * jacobsthal_sequence[i - 2];
		jacobsthal_sequence.push_back(next);
		++i;
		if (next >= n)
			break;
	}

	return jacobsthal_sequence;
}

int PmergeMe::binary_search_insert_position(const std::deque<int> &deque, int n)
{
	int low = 0;
	int high = deque.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (deque[mid] < n) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return low;
}

void	PmergeMe::insert(std::deque<int> &high, std::deque<int> &low)
{
	std::deque<int>	insertion_order = generateInsertionOrderDeque(low.size());

	for (size_t i = 0; i < insertion_order.size(); ++i)
	{
		int	n = insertion_order[i];
		int	pos = binary_search_insert_position(high, low[n]);

		high.insert(high.begin() + pos, low[n]);
	}
}

void	PmergeMe::insertRemainder(std::deque<int> &deque, int n)
{
	if (n != -1)
	{
		int pos = binary_search_insert_position(deque, n);
		deque.insert(deque.begin() + pos, n);
	}
}

std::deque<int>	PmergeMe::fordJohnsonSortDeque(std::deque<int> &deque)
{
	std::deque<int>	low, high;
	int					remainder = -1;

	if (deque.size() == 1)
		return deque;

	if (deque.size() % 2 == 1)
	{
		remainder = deque.back();
		deque.pop_back();
	}

	for (size_t i = 0; i < deque.size(); i += 2)
	{
		low.push_back(std::min(deque[i], deque[i + 1]));
		high.push_back(std::max(deque[i], deque[i + 1]));
	}

	high = fordJohnsonSortDeque(high);
	insert(high, low);
	insertRemainder(high, remainder);

	return high;
}

void	PmergeMe::insertArgumentsIntoDeque(int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		char* end;
		long number = std::strtol(av[i], &end, 10);
		_deque.push_back(static_cast<int>(number));
	}
}

void	PmergeMe::printDeque()
{
	std::cout << "Sorted deque: ";
	for (size_t i = 0; i < _deque.size(); ++i)
	{
		std::cout << _deque[i] << " ";
		if (i > 0 && _deque[i] < _deque[i - 1])
		{
			std::cout << "Deque not sorted";
			break;
		}
	}
	std::cout << std::endl;
}

void	PmergeMe::printArray(int ac, char **av) 
{
	std::cout << "Before:";
	for (int i = 1; i < ac; ++i)
	{
		std::cout << " " << av[i];
	}
	std::cout << std::endl;
}

void	PmergeMe::printElapsedTime(int elements, double elapsed_secs, bool vector)
{
	if (vector)
	{
		std::cout << "Vector: ";
	}
	else
	{
		std::cout << "Deque: ";
	}

	std::cout << elements << " elements, execution time: ";

	if (elapsed_secs >= 1.0)
	{
		std::cout << elapsed_secs << " seconds" << std::endl;
	}
	else if (elapsed_secs >= 1e-3)
	{
		std::cout << elapsed_secs * 1e3 << " milliseconds" << std::endl;
	}
	else if (elapsed_secs >= 1e-6)
	{
		std::cout << elapsed_secs * 1e6 << " microseconds" << std::endl;
	}
	else
	{
		std::cout << elapsed_secs * 1e9 << " nanoseconds" << std::endl;
	}
}

void	PmergeMe::checkArguments(int ac, char* av[])
{
	if (ac < 2)
	{
		throw std::invalid_argument("Usage: " + std::string(av[0]) + " <list of integers>");
	}
	for (int i = 1; i < ac; ++i)
	{
		char* end;
		long number = std::strtol(av[i], &end, 10);

		if (*end != '\0')
		{
			throw std::invalid_argument("Invalid number: " + std::string(av[i]));
		}

		if (number < 0)
		{
			throw std::invalid_argument("Negative number not allowed: " + std::string(av[i]));
		}

		if (number > INT_MAX)
		{
			throw std::invalid_argument("Number out of range: " + std::string(av[i]));
		}
	}
}
