//
// Created by Romeo on 22/06/2020.
//

#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <iostream>
#include <string>
#include <vector>
//#include "Operand.hpp"
#include "Exception.hpp"
//#include "Lexer.hpp"
#include "IOperand.hpp"
//#include "Factory.hpp"

class Computer
{
	//PRIVATE ATTRIBUT
	//const Factory						_factory;

	// _instructions
	const std::vector<std::string *>	*_command_list;

	//opStack
	std::vector<const IOperand *>		_operand_table;


	//PRIVATE CONSTRUCTOR
	Computer(const Computer &rhs) = default;
	Computer &	operator=(const Computer &rhs) = default;

	//Computer FUNCTIONS
	void 	push(const std::string &str);
	void 	pop();
	void 	dump() const;
	void 	assert(const std::string &str) const;
	void 	add();
	void 	sub();
	void 	mul();
	void 	div();
	void 	mod();
	void 	print() const;

public:
	Computer();
	Computer(const std::vector<std::string *> &command_list);
	~Computer() = default;

	//EXCUTING SCRIPT
	void 	doMagic();

	const IOperand *	createOperand(const eOperandType type, const std::string &value) const;

private:

	typedef const IOperand *(Computer::*OperandFunc)(const std::string &) const;

	// fList
	std::vector<OperandFunc> _func;

	IOperand const *	createInt8(const std::string &value) const;
	IOperand const *	createInt16(const std::string &value) const;
	IOperand const *	createInt32(const std::string &value) const;
	IOperand const *	createFloat(const std::string &value) const;
	IOperand const *	createDouble(const std::string &value) const;
};


#endif
