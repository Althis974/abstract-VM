//
// Created by Romeo on 22/06/2020.
//

#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <regex>
#include "Operand.hpp"

enum eCommandType
{
	PUSH,
	POP,
	DUMP,
	ASSERT,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	PRINT,
	EXIT,
	END,
	COMMENT,
	ERROR
};

namespace Lexer
{
	eCommandType	getCommandType(const std::string &s);
	eOperandType	getOperandType(const std::string &s);
	std::string		getOperandValue(const std::string &s);
};


#endif
