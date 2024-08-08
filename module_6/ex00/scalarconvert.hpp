#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#include <string>

class ScalarConvert
{
public:
	static void convert(const std::string& str);
private:
	ScalarConvert(const ScalarConvert &other);
	ScalarConvert &operator=(const ScalarConvert &other);
	ScalarConvert();
	~ScalarConvert();
};

#endif
