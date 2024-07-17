#ifndef INTERN_HPP
# define INTERN_HPP

#include "aform.hpp"
#include <string>


class Intern
{
public:
	AForm* makeForm(const std::string& name, const std::string& target);

	template <typename T>
	static AForm* createForm(const std::string& target)
	{
		return new T(target);
	}

private:

};

#endif
