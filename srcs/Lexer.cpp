//
// Created by Romeo on 22/06/2020.
//

#include "../includes/Lexer.hpp"

eInstructionType	Lexer::getInstructionType(const std::string &s)
{
	if (s.substr(0, 5) == "push ")
		return PUSH;
	else if (s.substr(0, 3) == "pop")
		return POP;
	else if (s.substr(0, 4) == "dump")
		return DUMP;
	else if (s.substr(0, 7) == "assert ")
		return ASSERT;
	else if (s.substr(0, 3) == "add")
		return ADD;
	else if (s.substr(0, 3) == "sub")
		return SUB;
	else if (s.substr(0, 3) == "mul")
		return MUL;
	else if (s.substr(0, 3) == "div")
		return DIV;
	else if (s.substr(0, 3) == "mod")
		return MOD;
	else if (s.substr(0, 5) == "print")
		return PRINT;
	else if (s.substr(0, 4) == "exit")
		return EXIT;
	else if (s.substr(0, 1) == ";")
		return COMMENT;
	else if (s.substr(0, 2) == ";;")
		return END;

	return ERROR;
}

eOperandType		Lexer::getOperandType(const std::string &s)
{
	std::string		operandType;

	operandType = s.substr(s.find(' ') + 1, s.size());

	if (operandType.substr(0, 4) == "int8")
		return INT8;
	else if (operandType.substr(0, 5) == "int16")
		return INT16;
	else if (operandType.substr(0, 5) == "int32")
		return INT32;
	else if (operandType.substr(0, 5) == "float")
		return FLOAT;
	else if (operandType.substr(0, 6) == "double")
		return DOUBLE;

	return UNKNOWN;
}

std::string			Lexer::getOperandValue(const std::string &s)
{
	std::string		operandValue;
	const char *	check;
	std::regex		numeric;

	operandValue = s.substr(s.find('(') + 1, s.size());
	numeric = ("^[0-9.-]*$");

	if (operandValue.find(')') != std::string::npos)
	{
		check = operandValue.substr(operandValue.find(')') + 1, std::string::npos).c_str();
		for (int i = 0; check[i]; ++i)
		{
			if (check[i] == ';')
				break ;
			if (check[i] != ' ')
				throw Exception::SyntaxException();
		}
	}

	operandValue = operandValue.substr(0, operandValue.find(')'));

	if (!std::regex_match(operandValue, numeric))
		throw Exception::SyntaxException();

	return (operandValue);
}