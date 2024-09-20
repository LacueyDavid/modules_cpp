#include "RPN.hpp"
/// clean function

long int RPN::charToLongInt(char charValue)
{
	return charValue - '0';
}

//// Struct StackElement

StackElement::StackElement() {}

StackElement::StackElement(const StackElement& other)
	: type(other.type)
{
	intValue = 0;
	charValue = 0;
	if (type == INT)
		intValue = other.intValue;
	else if (type == CHAR)
		charValue = other.charValue;
}

StackElement& StackElement::operator=(const StackElement& other)
{
	if (this == &other)
		return *this;
	type = other.type;
	intValue = 0;
	charValue = 0;
	if (type == INT)
		intValue = other.intValue;
	else if (type == CHAR)
		charValue = other.charValue;
	return *this;
}

StackElement::~StackElement() {}

StackElement::StackElement(long int value)
: type(INT)
	, intValue(value)
{}

StackElement::StackElement(char value)
: type(CHAR)
	, charValue(value)
{}

///// class

/// canonical form

RPN::RPN() {}

RPN::RPN(const RPN& other __attribute__((unused))) {}

RPN& RPN::operator=(const RPN& other __attribute__((unused))) { return *this; }

RPN::~RPN() {}

//// class functions

bool RPN::isOperator(const StackElement& elem) const
{
	return elem.type == CHAR;
}

void RPN::validateInput(const std::string& input) const
{
	for (size_t i = 0; i < input.size(); ++i)
	{
		char ch = input[i];
		if (i % 2 == 1 && ch != ' ')
			throw std::invalid_argument("Error");
		if (i % 2 == 0 && !isdigit(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/')
			throw std::invalid_argument("Error");
	}
}

void RPN::executeCalculation()
{
	if (operandStack.size() < 2)
		throw std::invalid_argument("Error");

	char op = rpnStack.top().charValue;
	rpnStack.pop();

	long int b = operandStack.top().intValue;
	operandStack.pop();

	long int a = operandStack.top().intValue;
	operandStack.pop();

	operandStack.push(performOperation(a, b, op));
}

void RPN::processOperand()
{
	if (rpnStack.empty())
		throw std::invalid_argument("Error");

	operandStack.push(rpnStack.top());
	rpnStack.pop();
}

long int RPN::performOperation(long int a, long int b, char op) const
{
	switch (op)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0)
				throw std::invalid_argument("Error");
			return a / b;
		default: throw std::invalid_argument("Error");
	}
}


long int RPN::getFinalResult() const
{
	if (operandStack.size() != 1)
		throw std::invalid_argument("Error");

	long int result = operandStack.top().intValue;
	if (result > INT_MAX || result < INT_MIN)
		throw std::invalid_argument("Error");

	return result;
}

void RPN::pushElementToStack(char charValue)
{
	if (isdigit(charValue))
		rpnStack.push(charToLongInt(charValue));
	else
		rpnStack.push(charValue);
}

void RPN::parseInputToStack(const std::string& input)
{
	for (int i = input.size() - 1; i >= 0; --i) {
		if (i % 2 == 0)
			pushElementToStack(input[i]);
	}
}

long int RPN::evaluateRPN(const std::string& input)
{
	validateInput(input);
	parseInputToStack(input);
	while (!rpnStack.empty()) {
		isOperator(rpnStack.top())
			? executeCalculation()
			: processOperand();
	}
	return getFinalResult();
}
