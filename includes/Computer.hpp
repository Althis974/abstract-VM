//
// Created by Romeo on 22/06/2020.
//

#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <iostream>
#include <string>
#include <list>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Exception.hpp"

typedef std::list<IOperand *> opStack;

class Computer
{

public:

		// Constructor
		Computer();

		// Copy constructor
		Computer(const Computer &src) = default;

		// Destructor
		~Computer() = default;

		// Assignation operator overload
		Computer & 	operator=(const Computer &rhs) = default;

		// Factory method
		IOperand *	createOperand(eOperandType type, const std::string &value);

		// Getter
		IOperand *	get();

		// Instructions
		void 		push(IOperand *rhs);
		void 		pop();
		void 		dump();
		void 		add();
		void 		sub();
		void 		mul();
		void 		div();
		void 		mod();

private:

		typedef IOperand *(Computer::*fPtr)(const std::string &);

		fPtr 		_fList[5];
		opStack 	_opStack;

		IOperand *	createInt8(const std::string &value);
		IOperand *	createInt16(const std::string &value);
		IOperand *	createInt32(const std::string &value);
		IOperand *	createFloat(const std::string &value);
		IOperand *	createDouble(const std::string &value);
};


#endif
