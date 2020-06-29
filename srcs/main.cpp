/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlossy <rlossy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 09:47:21 by rlossy            #+#    #+#             */
/*   Updated: 2020/06/29 09:53:19 by rlossy           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "../includes/Lexer.hpp"

int     ft_atoi(const std::string &s)
{
	std::stringstream	stringStream;
	int					nb;

	stringStream << s;
	stringStream >> nb;

	return (nb);
}

double  ft_atof(const std::string &s)
{
	std::stringstream	stringStream;
	double				nb;

	stringStream << s;
	stringStream >> nb;

	return (nb);
}

int		main(int ac, char **av)
{
	try
	{
		Lexer           lexer;
		std::string     line;

		if (ac == 2)
		{
			std::ifstream file(av[1], std::ios::in);
			if (!file)
				throw Exception("File not found");

			while (getline(file, line))
				lexer.fill(line);

			file.close();
			lexer.execute();
		}
		else
		{
			do
			{
				getline(std::cin, line, '\n');
				lexer.fill(line);
			} while (line.find(";;") == line.npos);
			lexer.execute();
		}
	}
	catch (const Exception &e)
	{
		std::cerr << "ERROR : " << e.what() << std::endl;
	}

	return (0);
}

