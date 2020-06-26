//
// Created by Romeo on 22/06/2020.
//

#include "../includes/Computer.hpp"
#include "../includes/Lexer.hpp"

// Constructors

Computer::Computer() : _instructions(nullptr)
{
	this->_functions.push_back(&Computer::createInt8);
	this->_functions.push_back(&Computer::createInt16);
	this->_functions.push_back(&Computer::createInt32);
	this->_functions.push_back(&Computer::createFloat);
	this->_functions.push_back(&Computer::createDouble);
}

Computer::Computer(const std::vector<std::string *> &instructions) : _instructions(&instructions)
{
	this->_functions.push_back(&Computer::createInt8);
	this->_functions.push_back(&Computer::createInt16);
	this->_functions.push_back(&Computer::createInt32);
	this->_functions.push_back(&Computer::createFloat);
	this->_functions.push_back(&Computer::createDouble);
}

// Destructor

Computer::~Computer()
{
		delete this->_instructions;
}

// Execute instructions

void				Computer::execute()
{
	std::vector<std::string *>::const_iterator	it;
	std::vector<std::string *>::const_iterator	ite;

	it = this->_instructions->begin();
	ite = this->_instructions->end();
	while (it != ite)
	{
		//TODO REPLACE SWITCH BY FUNCTION VECTOR (LIKE FACTORY)
		switch (Lexer::getInstructionType(**it))
		{
			case PUSH:
				this->push(**it);
				break ;

			case POP:
				this->pop();
				break ;

			case DUMP:
				this->dump();
				break ;

			case ASSERT:
				this->assert(**it);
				break ;

			case ADD:
				this->add();
				break ;

			case SUB:
				this->sub();
				break ;

			case MUL:
				this->mul();
				break ;

			case DIV:
				this->div();
				break ;

			case MOD:
				this->mod();
				break ;

			case PRINT:
				this->print();
				break ;

			case ERROR:
				throw Exception::UnknownInstructionException();

			default:
				break ;
		}
		++it;
	}
}

// Instructions

void 				Computer::push(const std::string &s)
{
	std::string		value;
	eOperandType 	operand_type;

	value = Lexer::getOperandValue(s);
	operand_type = Lexer::getOperandType(s);

	switch (operand_type)
	{
		case UNKNOWN:
			throw Exception::SyntaxException();

		default:
			this->_operands.push_back(createOperand(operand_type, value));
			break ;
	}
}

void				Computer::pop()
{

	if (this->_operands.empty())
		throw Exception::PopOnEmptyStackException();

	this->_operands.pop_back();
}

void				Computer::dump() const
{
	std::vector<const IOperand *>::const_reverse_iterator	it;
	std::vector<const IOperand *>::const_reverse_iterator	ite;

	it = this->_operands.rbegin();
	ite = this->_operands.rend();
	while (it != ite)
	{
		std::cout << (*it)->toString() << std::endl;
		++it;
	}
}

 void				Computer::assert(const std::string &s) const
 {
	std::string		value;

	if (this->_operands.empty())
		throw Exception::AssertException();

	value = Lexer::getOperandValue(s);
	const IOperand	&operand = **(this->_operands.rbegin());

	if (value != operand.toString())
		throw Exception::AssertException();
}

void				Computer::add()
{
	const IOperand *	a;
	const IOperand *	b;

	if (this->_operands.size() < 2)
		throw Exception::OperationOnEmptyStackException();

	a = *(this->_operands.rbegin());
	this->_operands.pop_back();
	b = *(this->_operands.rbegin());
	this->_operands.pop_back();
	this->_operands.push_back(*a + *b);

	delete a;
	delete b;
}

void				Computer::sub()
{
	const IOperand *	a;
	const IOperand *	b;

	if (this->_operands.size() < 2)
		throw Exception::OperationOnEmptyStackException();

	a = *(this->_operands.rbegin());
	this->_operands.pop_back();
	b = *(this->_operands.rbegin());
	this->_operands.pop_back();
	this->_operands.push_back(*a - *b);
}

 void				Computer::mul()
 {
	const IOperand *	a;
	const IOperand *	b;

	if (this->_operands.size() < 2)
		throw Exception::OperationOnEmptyStackException();

	a = *(this->_operands.rbegin());
	this->_operands.pop_back();
	b = *(this->_operands.rbegin());
	this->_operands.pop_back();
	this->_operands.push_back(*a * *b);
}

void				Computer::div()
{
	const IOperand *	a;
	const IOperand *	b;

	if (this->_operands.size() < 2)
		throw Exception::OperationOnEmptyStackException();

	a = *(this->_operands.rbegin());
	this->_operands.pop_back();
	b = *(this->_operands.rbegin());
	this->_operands.pop_back();
	this->_operands.push_back(*a / *b);
}

void 				Computer::mod()
{
	const IOperand *	a;
	const IOperand *	b;

	if (this->_operands.size() < 2)
		throw Exception::OperationOnEmptyStackException();

	a = *(this->_operands.rbegin());
	this->_operands.pop_back();
	b = *(this->_operands.rbegin());
	this->_operands.pop_back();
	this->_operands.push_back(*a % *b);
}

void 				Computer::print() const
{
	const IOperand *		iOperand;
	const Operand<char> *	operand;

	if (this->_operands.empty())
		throw Exception::PrintOnEmptyStackException();

	iOperand = *(this->_operands.rbegin());

	if (iOperand->getType() != INT8)
		throw Exception::PrintNonAsciiException();

	operand = dynamic_cast<const Operand<char> *>(iOperand);
	std::cout << operand->getValue() << std::endl;
}

// Factory method

const IOperand *	Computer::createOperand(const eOperandType type, std::string const &value) const
{
	return ((this->*(this->_functions[type]))(value));
}

// Factory functions

const IOperand *	Computer::createInt8(const std::string &value) const
{
	int						nb;
	std::ostringstream		oStringStream;

	nb = static_cast<char>(atoi(value.c_str()));
	oStringStream << nb;

	if (value.substr(0, value.find('.'))
		!= oStringStream.str().substr(0, oStringStream.str().find('.')))
	{
		if (value.find('-') != std::string::npos)
			throw Exception::UnderflowException();

		throw Exception::OverflowException();
	}

	return (new Operand<char>(INT8, static_cast<char>(nb)));
}

const IOperand *	Computer::createInt16(const std::string &value) const
{
	int 					nb;
	std::ostringstream		oStringStream;

	nb = static_cast<short>(atoi(value.c_str()));
	oStringStream << nb;

	if (value.substr(0, value.find('.'))
		!= oStringStream.str().substr(0, oStringStream.str().find('.')))
	{
		if (value.find('-') != std::string::npos)
			throw Exception::UnderflowException();

		throw Exception::OverflowException();
	}

	return (new Operand<short>(INT16, static_cast<short>(nb)));
}

const IOperand *	Computer::createInt32(const std::string &value) const
{
	int 					nb;
	std::ostringstream		oStringStream;

	nb = atoi(value.c_str());
	oStringStream << nb;

	if (value.substr(0, value.find('.'))
		!= oStringStream.str().substr(0, oStringStream.str().find('.')))
	{
		if (value.find('-') != std::string::npos)
			throw Exception::UnderflowException();

		throw Exception::OverflowException();
	}

	return (new Operand<int>(INT32, nb));
}

const IOperand *	Computer::createFloat(const std::string &value) const
{
	double 					nb;
	std::ostringstream		oStringStream;

	nb = static_cast<float>(atof(value.c_str()));
	oStringStream << nb;

	if (value.substr(0, value.find('.'))
		!= oStringStream.str().substr(0, oStringStream.str().find('.')))
	{
		if (value.find('-') != std::string::npos)
			throw Exception::UnderflowException();

		throw Exception::OverflowException();
	}

	return (new Operand<float>(FLOAT, static_cast<float>(nb)));
}

const IOperand *	Computer::createDouble(const std::string &value) const
{
	double 					nb;
	std::ostringstream		oStringStream;

	nb = atof(value.c_str());
	oStringStream << nb;

	if (value.substr(0, value.find('.'))
		!= oStringStream.str().substr(0, oStringStream.str().find('.')))
	{
		if (value.find('-') != std::string::npos)
			throw Exception::UnderflowException();

		throw Exception::OverflowException();
	}

	return (new Operand<double>(DOUBLE, nb));
}
