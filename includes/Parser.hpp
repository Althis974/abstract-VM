/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlossy <rlossy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 09:57:34 by rlossy            #+#    #+#             */
/*   Updated: 2020/06/29 09:57:34 by rlossy           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Exception.hpp"
#include "unistd.h"

# define BUFF_SIZE 256

class Parser
{

public:

		// Constructor
		Parser() = default;

		// Copy constructor
		Parser(const Parser &rhs) = default;

		// Destructor
		~Parser();

		// Assignation operator overload
		Parser &							operator=(const Parser &rhs) = default;

		// Parsing
		std::vector<std::string *> const & 	readFile(const char *filename);
		std::vector<std::string *> const & 	readStdin();

private:

		std::vector<std::string *> *		_instructions;
};

#endif
