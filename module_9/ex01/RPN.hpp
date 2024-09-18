#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

class RPN
{
private:
	std::string input;
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
public:
	RPN(const std::string &input);
	~RPN();
};

#endif
