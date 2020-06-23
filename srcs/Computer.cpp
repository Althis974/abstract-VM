//
// Created by Romeo on 22/06/2020.
//

#include "../includes/Computer.hpp"

Computer::Computer()
{
	this->_fList[0] = &Computer::createInt8;
	this->_fList[1] = &Computer::createInt16;
	this->_fList[2] = &Computer::createInt32;
	this->_fList[3] = &Computer::createFloat;
	this->_fList[4] = &Computer::createDouble;
}

IOperand *		Computer::createOperand(eOperandType type, const std::string &value)
{
	return ((this->*_fList[type])(value));
}

IOperand *		Computer::get()
{
	if (this->_opStack.empty())
		return (nullptr);

	return (this->_opStack.front());
}

void			Computer::push(IOperand *rhs)
{
	this->_opStack.push_front(rhs);
}

void			Computer::pop()
{
	if (this->_opStack.empty())
		throw Exception("Pop on empty stack.");

	this->_opStack.pop_front();
}

void			Computer::dump()
{
	if (this->_opStack.empty())
		throw Exception("Dump on empty stack.");

	for (auto & op : this->_opStack)
		std::cout << op->toString() << std::endl;
}

void			Computer::add()
{
	if (this->_opStack.empty())
		throw Exception("Caclulation without two parameters in stack.");

	IOperand		*a = get();
	pop();
	IOperand		*b = get();
	pop();

	push(const_cast<IOperand *>(*a + *b));
}

void		Computer::sub()
{
	if (this->_opStack.empty())
		throw Exception("Caclulation without two parameters in stack.");

	IOperand		*a = get();
	pop();
	IOperand		*b = get();
	pop();

	push(const_cast<IOperand *>(*a - *b));
}

void		Computer::mul()
{
	if (this->_opStack.empty())
		throw Exception("Caclulation without two parameters in stack.");

	IOperand		*a = get();
	pop();
	IOperand		*b = get();
	pop();

	push(const_cast<IOperand *>(*a * *b));
}

void		Computer::div()
{
	if (this->_opStack.empty())
		throw Exception("Caclulation without two parameters in stack.");

	IOperand		*a = get();
	pop();
	IOperand		*b = get();
	pop();

	push(const_cast<IOperand *>(*a / *b));
}

void		Computer::mod()
{
	if (this->_opStack.empty())
		throw Exception("Caclulation without two parameters in stack.");

	IOperand		*a = get();
	pop();
	IOperand		*b = get();
	pop();

	push(const_cast<IOperand *>(*a % *b));
}

IOperand *		Computer::createInt8(const std::string &value)
{
	IOperand		*operand;

	operand = new Operand<char>(INT8, ft_atof(value));

	return (operand);
}

IOperand *		Computer::createInt16(const std::string &value)
{
	IOperand		*operand;

	operand = new Operand<short>(INT16, ft_atof(value));

	return (operand);
}

IOperand *		Computer::createInt32(const std::string &value)
{
	IOperand		*operand;

	operand = new Operand<int>(INT32, ft_atof(value));

	return (operand);
}

IOperand *		Computer::createFloat(const std::string &value)
{
	IOperand		*operand;

	operand = new Operand<float>(FLOAT, ft_atof(value));

	return (operand);
}

IOperand *		Computer::createDouble(const std::string &value)
{
	IOperand		*operand;

	operand = new Operand<double>(DOUBLE, ft_atof(value));

	return (operand);
}