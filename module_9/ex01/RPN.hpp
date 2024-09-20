// #ifndef RPN_HPP
// # define RPN_HPP
//
// #include <string>
// #include <iostream>
// #include <cstdlib>
// #include <sstream>
// #include <stack>
//
// enum Type
// {
// 	INT,
// 	CHAR
// };
//
// class RPN
// {
// private:
// 	std::string input;
// 	RPN();
// 	RPN(const RPN &other);
// 	RPN &operator=(const RPN &other);
// public:
// 	RPN(const std::string &input);
// 	~RPN();
// };
//
// struct StackElement
// {
// 	Type type;
//
// 	union
// 	{
// 		int intValue;
// 		char charValue;
// 	};
//
// 	StackElement(int value) : type(INT), intValue(value) {}
// 	StackElement(char value) : type(CHAR), charValue(value) {}
// 	StackElement(const StackElement& other)
// 		: type(other.type)
// 	{
// 		if (type == INT)
// 			intValue = other.intValue;
// 		else if (type == CHAR)
// 			charValue = other.charValue;
// 	}
// 	StackElement &operator=(const StackElement &other)
// 	{
// 		if (&other != this)
// 			return *this;
// 		type = other.type;
// 		if (type == INT)
// 		{
// 			intValue = other.intValue;
// 			charValue = 0;
// 		}
// 		else if (type == CHAR)
// 		{
// 			charValue = other.charValue;
// 			intValue = 0;
// 		}
// 		return *this;
// 	}
// };
//
// #endif
