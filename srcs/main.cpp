#include <iostream>
#include "../includes/Parser.hpp"
#include "../includes/Computer.hpp"

int		main(int ac, char **av)
{
	try
	{
		if (ac == 2)
		{
			Computer	comp1(Parser::readFile(av[1]));

			comp1.execute();
		}
		else if (ac == 1)
		{
			Computer	comp2(Parser::readStdin());

			comp2.execute();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

