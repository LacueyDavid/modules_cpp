#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	Harl karen; karen.complain(argv[1]);
}
