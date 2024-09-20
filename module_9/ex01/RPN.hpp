#ifndef RPN_HPP
# define RPN_HPP

#include <climits>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <cctype>
#include <cstdlib>

enum Type { INT, CHAR };

struct StackElement
{
public:
	Type type;

	union
	{
		long int intValue;
		char charValue;
	};

	StackElement(long int value);
	StackElement(char value);

	StackElement& operator=(const StackElement& other);
	StackElement(const StackElement& other);
	~StackElement();
private:
	StackElement();
};

class RPN
{
public:
	long int evaluateRPN(const std::string& input);

	RPN();
	~RPN();

private:
	std::stack<StackElement> rpnStack;
	std::stack<StackElement> operandStack;

	long int charToLongInt(char charValue);
	void validateInput(const std::string& input) const;
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

	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
};

#endif
