//
// Created by Romeo on 22/06/2020.
//

#include "../includes/Computer.hpp"
#include "../includes/Lexer.hpp"

Computer::Computer() : _command_list(nullptr)
{
	this->_func.push_back(&Computer::createInt8);
	this->_func.push_back(&Computer::createInt16);
	this->_func.push_back(&Computer::createInt32);
	this->_func.push_back(&Computer::createFloat);
	this->_func.push_back(&Computer::createDouble);
}

//TODO GET STD::VECTOR

Computer::Computer(const std::vector<std::string *> &command_list) : _command_list(&command_list)
{
	this->_func.push_back(&Computer::createInt8);
	this->_func.push_back(&Computer::createInt16);
	this->_func.push_back(&Computer::createInt32);
	this->_func.push_back(&Computer::createFloat);
	this->_func.push_back(&Computer::createDouble);
}

void		Computer::doMagic()
{
	std::vector<std::string *>::const_iterator		it;
	std::vector<std::string *>::const_iterator		ite;

	it = _command_list->begin();
	ite = _command_list->end();
	while (it != ite) {
		//TODO REPLACE SWITCH BY FUNCTION VECTOR (LIKE FACTORY)
		switch (Lexer::getCommandType(**it)) {
			case ERROR:
				throw Exception::UnknownInstructionException();
			case DUMP:
				this->dump();
				break ;
			case PUSH:
				this->push(**it);
				break ;
			case POP:
				this->pop();
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
			default:
				break ;
		}
		it++;
	}
}

void 								Computer::push(const std::string &str) {
	eOperandType 					operand_type = Lexer::getOperandType(str);
	std::string						value = Lexer::getOperandValue(str);

	switch (operand_type) {
		case UNKNOWN:
			throw Exception::SyntaxException();
		default:
			_operand_table.push_back(createOperand(operand_type, value));
			break ;
	}
}

void								Computer::pop() {
	if (_operand_table.empty())
		throw Exception::PopOnEmptyStackException();
	_operand_table.pop_back();
}

void								Computer::dump() const {
	std::vector<const IOperand *>::const_reverse_iterator	it;
	std::vector<const IOperand *>::const_reverse_iterator	ite;

	it = _operand_table.rbegin();
	ite = _operand_table.rend();
	while (it != ite) {
		std::cout << (*it)->toString() << std::endl;
		it++;
	}
}

 void								Computer::assert(const std::string &str) const {
	if (!_operand_table.size())
		throw Exception::AssertException();

	std::string						value = Lexer::getOperandValue(str);
	const IOperand					&operand = **(_operand_table.rbegin());

	if (value != operand.toString())
		throw Exception::AssertException();
}

void								Computer::add() {
	const IOperand					*o1 = NULL;
	const IOperand					*o2 = NULL;

	if (_operand_table.size() < 2)
		throw Exception::OperationOnEmptyStackException();
	o1 = *(_operand_table.rbegin());
	_operand_table.pop_back();
	o2 = *(_operand_table.rbegin());
	_operand_table.pop_back();
	_operand_table.push_back(*o1 + *o2);
}

void								Computer::sub() {
	const IOperand					*o1 = NULL;
	const IOperand					*o2 = NULL;

	if (_operand_table.size() < 2)
		throw Exception::OperationOnEmptyStackException();
	o1 = *(_operand_table.rbegin());
	_operand_table.pop_back();
	o2 = *(_operand_table.rbegin());
	_operand_table.pop_back();
	_operand_table.push_back(*o1 - *o2);
}

 void								Computer::mul()
 {
	const IOperand					*o1 = nullptr;
	const IOperand					*o2 = nullptr;

	if (_operand_table.size() < 2)
		throw Exception::OperationOnEmptyStackException();

	o1 = *(_operand_table.rbegin());
	_operand_table.pop_back();
	o2 = *(_operand_table.rbegin());
	_operand_table.pop_back();
	_operand_table.push_back(*o1 * *o2);
}

void								Computer::div() {
	const IOperand					*o1 = NULL;
	const IOperand					*o2 = NULL;

	if (_operand_table.size() < 2)
		throw Exception::OperationOnEmptyStackException();
	o1 = *(_operand_table.rbegin());
	_operand_table.pop_back();
	o2 = *(_operand_table.rbegin());
	_operand_table.pop_back();
	_operand_table.push_back(*o1 / *o2);
}

void 								Computer::mod() {
	const IOperand					*o1 = NULL;
	const IOperand					*o2 = NULL;

	if (_operand_table.size() < 2)
		throw Exception::OperationOnEmptyStackException();
	o1 = *(_operand_table.rbegin());
	_operand_table.pop_back();
	o2 = *(_operand_table.rbegin());
	_operand_table.pop_back();
	_operand_table.push_back(*o1 % *o2);
}

void 								Computer::print() const {
	const IOperand					*ioperand = NULL;
	const Operand<char>				*operand = NULL;

	if (_operand_table.empty())
		throw Exception::PrintOnEmptyStackException();
	ioperand = *(_operand_table.rbegin());
	if (ioperand->getType() != INT8)
		throw Exception::PrintNonAsciiException();
	operand = static_cast<const Operand<char> *>(ioperand);
	std::cout << operand->getValue() << std::endl;
}


// Factory methods

const IOperand *			Computer::createOperand(const eOperandType type, std::string const &value) const
{
	return ((this->*(this->_func[type]))(value));
}

const IOperand *			Computer::createInt8(const std::string &value) const
{
	int						number = static_cast<char>(atoi(value.c_str()));
	std::ostringstream		ss;

	ss << number;
	if (value.substr(0, value.find('.')).compare(ss.str().substr(0, ss.str().find('.'))) != 0)
	{
		if (value.find('-') != std::string::npos)
			throw Exception::UnderflowException();

		throw Exception::OverflowException();
	}

	return (new Operand<char>(INT8, static_cast<char>(number)));
}

const IOperand *			Computer::createInt16(const std::string &value) const
{
	int 					number = static_cast<short>(atoi(value.c_str()));
	std::ostringstream		ss;

	ss << number;
	if (value.substr(0, value.find('.')).compare(ss.str().substr(0, ss.str().find('.'))) != 0)
	{
		if (value.find('-') != std::string::npos)
			throw Exception::UnderflowException();

		throw Exception::OverflowException();
	}

	return (new Operand<short>(INT16, static_cast<short>(number)));
}

const IOperand *			Computer::createInt32(const std::string &value) const
{
	int 					number = atoi(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.substr(0, value.find('.')).compare(ss.str().substr(0, ss.str().find('.'))) != 0)
	{
		if (value.find('-') != std::string::npos)
			throw Exception::UnderflowException();

		throw Exception::OverflowException();
	}

	return (new Operand<int>(INT32, number));
}

const IOperand *			Computer::createFloat(const std::string &value) const
{
	double 					number = static_cast<float>(atof(value.c_str()));
	std::ostringstream		ss;

	ss << number;
	if (value.substr(0, value.find('.')).compare(ss.str().substr(0, ss.str().find('.'))) != 0)
	{
		if (value.find('-') != std::string::npos)
			throw Exception::UnderflowException();

		throw Exception::OverflowException();
	}

	return (new Operand<float>(FLOAT, static_cast<float>(number)));
}

const IOperand *			Computer::createDouble(const std::string &value) const
{
	double 					number = atof(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.substr(0, value.find('.')).compare(ss.str().substr(0, ss.str().find('.'))) != 0)
	{
		if (value.find('-') != std::string::npos)
			throw Exception::UnderflowException();

		throw Exception::OverflowException();
	}

	return (new Operand<double>(DOUBLE, number));
}