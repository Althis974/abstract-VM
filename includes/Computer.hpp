//
// Created by Romeo on 22/06/2020.
//

#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Exception.hpp"
#include "IOperand.hpp"

class Computer
{

public:

		// Constructors
		Computer();
		Computer(const std::vector<std::string *> &instructions);

		// Copy constructor
		Computer(const Computer &rhs) = default;

		// Destructor
		~Computer();

		// Assignation operator overload
		Computer &							operator=(const Computer &rhs) = default;

		// Execute instructions
		void 								execute();

		// Factory method
		const IOperand *					createOperand(const eOperandType type, const std::string &value) const;

private:

		// Pointers on member functions
		typedef const IOperand *(Computer::*OperandFunc)(const std::string &) const;

		// Functions list
		std::vector<OperandFunc>			_functions;

		// Instructions list
		const std::vector<std::string *> *	_instructions;

		// Operands list
		std::vector<const IOperand *>		_operands;

		// Instructions
		void 								push(const std::string &s);
		void 								pop();
		void 								dump() const;
		void 								assert(const std::string &s) const;
		void 								add();
		void 								sub();
		void 								mul();
		void 								div();
		void 								mod();
		void 								print() const;

		// Factory functions
		IOperand const *					createInt8(const std::string &value) const;
		IOperand const *					createInt16(const std::string &value) const;
		IOperand const *					createInt32(const std::string &value) const;
		IOperand const *					createFloat(const std::string &value) const;
		IOperand const *					createDouble(const std::string &value) const;
};


#endif
