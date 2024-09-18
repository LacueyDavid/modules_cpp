#include "RPN.hpp"

// private

RPN::RPN(){}

RPN::RPN(const RPN &other __attribute__((unused))){}

RPN &RPN::operator=(const RPN &other __attribute__((unused))){ return *this; }

// public

RPN::RPN(const std::string &input)
	: input(input)
{
	std::cout << "constructor called\n";
	std::cout << input << "\n";
}

RPN::~RPN()
{
	std::cout << "destructor called\n";
}
