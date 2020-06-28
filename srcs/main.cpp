#include <iostream>
#include "../includes/Parser.hpp"
#include "../includes/Computer.hpp"

int		main(int ac, char **av)
{
	try
	{
		if (ac == 2)
		{
			Parser		parse1{};
			Computer	comp1(parse1.readFile(av[1]));

			comp1.execute();
		}
		else if (ac == 1)
		{
			Parser		parse2{};
			Computer	comp2(parse2.readStdin());

			comp2.execute();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

