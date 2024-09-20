#include <climits>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <cctype>
#include <cstdlib>

enum Type { INT, CHAR };

class StackElement {
public:
	Type type;
	long int intValue;
	char charValue;

	StackElement(long int value) : type(INT), intValue(value), charValue(0) {}
	StackElement(char value) : type(CHAR), intValue(0), charValue(value) {}
};

class RPN {
public:
	// Canonical form constructors
	RPN() {}
	RPN(const RPN& other) { (void)other; }
	RPN& operator=(const RPN& other) { (void)other; return *this; }
	~RPN() {}

	void validateInput(const std::string& input);
	long int evaluateRPN(const std::string& input);

private:
	std::stack<StackElement> rpnStack;
	std::stack<StackElement> operandStack;

	bool isOperator(const StackElement& elem) const;
	void validateCharacter(char ch) const;
	void validateInputCharacters(const std::string& input) const;
	void validateSpacingInInput(const std::string& input) const;
	long int performOperation(long int a, long int b, char op) const;
	void executeCalculation();
	void processOperand();
	void processOperator();
	bool isFinalResultReady() const;
	bool hasTooManyOperands() const;
	long int getFinalResult() const;
	void pushElementToStack(char charValue);
	void parseInputToStack(const std::string& input);
};

bool RPN::isOperator(const StackElement& elem) const
{
	return elem.type == CHAR;
}

void RPN::validateCharacter(char ch) const
{
	if (!isdigit(ch) && ch != ' ' && !isOperator(ch))
		throw std::invalid_argument("Error");
}

void RPN::validateInputCharacters(const std::string& input) const
{
	for (size_t i = 0; i < input.size(); ++i)
		validateCharacter(input[i]);
}

void RPN::validateSpacingInInput(const std::string& input) const
{
	for (size_t i = 0; i < input.size(); ++i)
	{
		if (i % 2 == 1 && input[i] != ' ')
			throw std::invalid_argument("Error");
		if (i % 2 == 0 && (!isdigit(input[i]) && !isOperator(input[i])))
			throw std::invalid_argument("Error");
	}
}

void RPN::validateInput(const std::string& input)
{
	validateInputCharacters(input);
	validateSpacingInInput(input);
}

long int RPN::performOperation(long int a, long int b, char op) const
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
			{
				throw std::invalid_argument("Error");
			}
			return a / b;
		default:
			throw std::invalid_argument("Error");
	}
}

void RPN::executeCalculation()
{
	if (operandStack.size() < 2)
		throw std::invalid_argument("Error");

	StackElement operatorElem = rpnStack.top();
	rpnStack.pop();
	char op = operatorElem.charValue;

	long int b = operandStack.top().intValue;
	operandStack.pop();

	long int a = operandStack.top().intValue;
	operandStack.pop();

	long int result = performOperation(a, b, op);
	operandStack.push(result);
}

void RPN::processOperand()
{
	if (rpnStack.empty())
		throw std::invalid_argument("Error");
	operandStack.push(rpnStack.top());
	rpnStack.pop();
}

void RPN::processOperator()
{
	if (rpnStack.empty())
		throw std::invalid_argument("Error");
	executeCalculation();
}

bool RPN::isFinalResultReady() const
{
	return rpnStack.empty() && operandStack.size() == 1;
}

bool RPN::hasTooManyOperands() const
{
	return rpnStack.empty() && operandStack.size() > 1;
}

long int RPN::getFinalResult() const
{
	if (operandStack.empty())
		throw std::invalid_argument("Error");
	StackElement result = operandStack.top();
	if (result.type == INT)
	{
		if (result.intValue > INT_MAX)
			throw std::invalid_argument("Error");
		return result.intValue;
	}
	else
		throw std::invalid_argument("Error");
}

long int RPN::evaluateRPN(const std::string& input)
{
	validateInput(input);
	parseInputToStack(input);

	while (!rpnStack.empty())
	{
		if (!isOperator(rpnStack.top()))
			processOperand();
		else
			processOperator();
		if (isFinalResultReady())
			return getFinalResult();
		else if (hasTooManyOperands())
			throw std::invalid_argument("Error");
	}

	throw std::invalid_argument("Error");
}

void RPN::pushElementToStack(char charValue)
{
	if (isdigit(charValue))
	{
		long int intValue = charValue - '0';
		rpnStack.push(intValue);
	}
	else
		rpnStack.push(charValue);
}

void RPN::parseInputToStack(const std::string& input)
{
	for (int i = input.size() - 1; i >= 0; --i)
	{
		if (i % 2 == 0)
			pushElementToStack(input[i]);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <expression>\n";
		return EXIT_FAILURE;
	}

	RPN rpn;

	try
	{
		long int result = rpn.evaluateRPN(argv[1]);
		std::cout << "Result: " << result << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
