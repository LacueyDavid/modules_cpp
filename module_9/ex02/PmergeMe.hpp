#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <string>

class PmergeMe
{

public:
	PmergeMe(int ac, char **av);
	~PmergeMe();
	void execute();
	void executeTests();

private:

	int ac;
	char **av;

	std::deque<int> _deque;
	std::vector<int> _vector;

	double _elapsed_time_vector;
	double _elapsed_time_deque;

	void checkArguments();
	void printArray();
    void printElapsedTimes();
    void printElapsedTime(const std::string &container_name, size_t size,
				double elapsed_time);

	////////////// VECTOR //////////////
	void printVector();

	void startSortingVector();
	void fillVector();
	std::vector<int> mergeInsertSortVector(std::vector<int> &vector);
	bool vectorIsOdd(const std::vector<int> &vector);
	int setRemainderVector(std::vector<int> &vector);
	void createPair(std::vector<int> &main, std::vector<int> &pend,
				const std::vector<int> &vector);
	void insert(std::vector<int> &main, std::vector<int> &pend);
	void insertRemainder(std::vector<int> &main, int remainder);
	int binary_search_insert_position(const std::vector<int> &vector, int value);
	std::vector<int> generateInsertionOrderVector(int pendSize);
	std::vector<int> generateJacobsthalSequenceVector(int pendSize);

	////////////// DEQUE //////////////
	void startSortingDeque();
	void fillDeque();
	std::deque<int> mergeInsertSortDeque(std::deque<int> &deque);
	bool dequeIsOdd(const std::deque<int> &deque);
	int setRemainderDeque(std::deque<int> &deque);
	void createPair(std::deque<int> &main, std::deque<int> &pend,
				const std::deque<int> &deque);
	void insert(std::deque<int> &main, std::deque<int> &pend);
	void insertRemainder(std::deque<int> &main, int remainder);
	int binary_search_insert_position(const std::deque<int> &deque, int value);
	std::deque<int> generateInsertionOrderDeque(int pendSize);
	std::deque<int> generateJacobsthalSequenceDeque(int pendSize);

	PmergeMe();
	PmergeMe(const PmergeMe &pmergeMe);
	PmergeMe &operator=(const PmergeMe &pmergeMe);

	////////////// TESTS //////////////
	void testIsVectorSorted();
	void testIsDequeSorted();
};

#endif
