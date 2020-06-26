//
// Created by Romeo on 22/06/2020.
//

#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <regex>
#include "Operand.hpp"

enum eInstructionType
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
	COMMENT,
	END,
	ERROR
};

namespace Lexer
{
	eInstructionType	getInstructionType(const std::string &s);
	eOperandType		getOperandType(const std::string &s);
	std::string			getOperandValue(const std::string &s);
};


#endif
