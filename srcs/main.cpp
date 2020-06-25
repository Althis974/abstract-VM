#include <string>
#include <iostream>
#include <fstream>
#include "../includes/Parser.hpp"
#include "../includes/Computer.hpp"

int		main(int ac, char **av)
{
	try {
		if (ac == 2) {
			Computer	calculator(Parser::readFile(av[1]));

			calculator.doMagic();
		}
		else if (ac == 1) {
			Computer	cal(Parser::readStdin());

			cal.doMagic();
		}
	} catch (std::exception &e) {
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}

