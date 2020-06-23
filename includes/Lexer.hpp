//
// Created by Romeo on 22/06/2020.
//

#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <list>
#include "Computer.hpp"
#include "Operand.hpp"

class Lexer
{

public:

		// Constructor
		Lexer() = default;

		// Copy constructor
		Lexer(const Lexer &src) = default;

		// Destructor
		~Lexer() = default;

		// Assignation operator overload
		Lexer & operator=(const Lexer &rhs) = default;

		// Fill instructions list
		void fill(const std::string &str);

		// Tokenize instructions list
		std::list<std::string> tokenize(const std::string &line);

		// Execute instructions list
		void execute();

private:

		std::list<std::string> _instructions;
};


#endif
