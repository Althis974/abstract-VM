//
// Created by Romeo on 24/06/2020.
//

#ifndef PARSER_HPP
#define PARSER_HPP

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Exception.hpp"

// For Win only
#include "unistd.h"

# define BUFF_SIZE 256
/*
namespace Parser
{
	std::vector<std::string *> const &	readFile(const char *filename);
	std::vector<std::string *> const &	readStdin();
	//void 								clean();

	//std::string * tmp;
};*/

class Parser
{

public:

		Parser();
		~Parser();

		std::vector<std::string *> const & readFile(const char *filename);
		std::vector<std::string *> const & readStdin();

private:

		std::vector<std::string *> *	_instructions;
};

#endif
