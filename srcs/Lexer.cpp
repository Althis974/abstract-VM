//
// Created by Romeo on 22/06/2020.
//

#include "../includes/Lexer.hpp"

//LEXER
//TODO JE RISQUE D'AVOIR UN PROBLEME ENTRE LES COMMENTAIRES ET LA FIN DES ENTREE (';;')
eCommandType		Lexer::getCommandType(const std::string &s)
{
	if (s.substr(0, 5) == "push ")
		return PUSH;
	if (s.substr(0, 7) == "assert ")
		return ASSERT;
	if (s.substr(0, 1) == ";")
		return COMMENT;
	if (s.substr(0, 3) == "pop")
		return POP;
	if (s.substr(0, 4) == "dump")
		return DUMP;
	if (s.substr(0, 3) == "add")
		return ADD;
	if (s.substr(0, 3) == "sub")
		return SUB;
	if (s.substr(0, 3) == "mul")
		return MUL;
	if (s.substr(0, 3) == "div")
		return DIV;
	if (s.substr(0, 3) == "mod")
		return MOD;
	if (s.substr(0, 5) == "print")
		return PRINT;
	if (s.substr(0, 4) == "exit")
		return EXIT;
	if (s.substr(0, 2) == ";;")
		return END;

	return ERROR;
}

eOperandType		Lexer::getOperandType(const std::string &s)
{
	std::string		operand_type;

	operand_type = s.substr(s.find(' ') + 1, s.size());

	if (operand_type.substr(0, 4) == "int8")
		return INT8;
	if (operand_type.substr(0, 5) == "int16")
		return INT16;
	if (operand_type.substr(0, 5) == "int32")
		return INT32;
	if (operand_type.substr(0, 5) == "float")
		return FLOAT;
	if (operand_type.substr(0, 6) == "double")
		return DOUBLE;

	return UNKNOWN;
}

std::string			Lexer::getOperandValue(const std::string &s)
{
	const char *	check;
	std::string		operand_value;
	std::regex		num;

	operand_value = s.substr(s.find('(') + 1, s.size());
	num = ("^[0-9.-]*$");

	if (operand_value.find(')') != std::string::npos)
	{
		check = operand_value.substr(operand_value.find(')') + 1, std::string::npos).c_str();
		for (int i = 0; check[i]; ++i)
		{
			if (check[i] == ';')
				break ;
			if (check[i] != ' ')
				throw Exception::SyntaxException();
		}
	}

	operand_value = operand_value.substr(0, operand_value.find(')'));

	if (!std::regex_match(operand_value, num))
		throw Exception::SyntaxException();

	return (operand_value);
}