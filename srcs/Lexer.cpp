//
// Created by Romeo on 22/06/2020.
//

#include "../includes/Lexer.hpp"

// Fill instructions list

void Lexer::fill(const std::string &s)
{
	if (s[0] != ';')
		this->_instructions.push_back(s);
}

// Tokenize instructions

std::list<std::string> Lexer::tokenize(const std::string &line)
{
	std::string tmp;
	std::list<std::string> tokens;

	for (int i = 0; line.c_str()[i]; ++i)
	{
		if (line.c_str()[i] == ' ' || line.c_str()[i] == '(' || line.c_str()[i] == ')')
		{
			++i;
			tokens.push_back(tmp);
			tmp.clear();
		}
		tmp += line.c_str()[i];
	}

	return (tokens);
}

// Execute instructions list

void Lexer::execute()
{
	Computer computer;
	std::string tmp;
	std::string line;

	//for (std::list<std::string>::iterator it = this->_instructions.begin();
	//	 it != this->_instructions.end(); ++it)
	for (auto & _instruction : this->_instructions)
	{
		line = _instruction;
		for (int i = 0; line.c_str()[i]; ++i)
		{
			if (line.c_str()[i] == ')')
			{
				std::list<std::string> tokens = tokenize(line);
				if (tokens.front() == "push")
				{
					tokens.pop_front();
					int x = 0;
					while (operands[x++].name != tokens.front()){}
					tokens.pop_front();
					IOperand *op = computer.createOperand(operands[x - 1].type, tokens.front());
					tokens.pop_front();
					computer.push(op);

				}
				else if (tokens.front() == "assert")
				{
					tokens.pop_front();
					IOperand *op = computer.get();
					if (ft_atoi(tokens.front()) == op->getType())
					{
						tokens.pop_front();
						if (tokens.front() != op->toString())
							throw Exception("assert instruction not verify. 1");
						tokens.pop_front();
					}
					else
						throw Exception("assert instruction not verify. 2");
				}
			}
		}
		if (line == "add")
			computer.add();
		else if (line == "sub")
			computer.sub();
		else if (line == "mul")
			computer.mul();
		else if (line == "div")
			computer.div();
		else if (line == "mod")
			computer.mod();
		else if (line == "pop")
			computer.pop();
		else if (line == "dump")
			computer.dump();
	}
	if (line != "exit")
		throw Exception("No exit instruction found.");
}