//
// Created by Romeo on 25/06/2020.
//

#include "../includes/Factory.hpp"
#include "../includes/Exception.hpp"
#include "../includes/Operand.hpp"

Factory::Factory(void) {
	this->_func.push_back(&Factory::createInt8);
	this->_func.push_back(&Factory::createInt16);
	this->_func.push_back(&Factory::createInt32);
	this->_func.push_back(&Factory::createFloat);
	this->_func.push_back(&Factory::createDouble);
}

//PUBLIC DESTRUCTOR
Factory::~Factory(void) {}

//PRIVATE CONSTRUCTOR
Factory::Factory(const Factory &rhs) {
	static_cast<void>(rhs);
	Factory();
}

Factory &
Factory::operator=(const Factory &rhs) const {
	return (*new Factory(rhs));
}

// Factory methods

const IOperand *			Factory::createOperand(const eOperandType type, std::string const &value) const
{
	return ((this->*(this->_func[type]))(value));
}

const IOperand *			Factory::createInt8(const std::string &value) const
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

const IOperand *			Factory::createInt16(const std::string &value) const
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

const IOperand *			Factory::createInt32(const std::string &value) const
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

const IOperand *			Factory::createFloat(const std::string &value) const
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

const IOperand *			Factory::createDouble(const std::string &value) const
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