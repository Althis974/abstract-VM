//
// Created by Romeo on 22/06/2020.
//

#include "../includes/Exception.hpp"

const char *	Exception::OverflowException::what() const throw()
{
	return ("OverflowException: Overflow on a value!");
}

const char *	Exception::UnderflowException::what() const throw()
{
	return ("UnderflowException: Underflow on a value!");
}

const char *	Exception::SyntaxException::what() const throw()
{
	return ("SyntaxException: Syntax error!");
}

const char *	Exception::UnknownInstructionException::what() const throw()
{
	return ("UnknownInstructionException: Unknown instruction!");
}

const char *	Exception::PopOnEmptyStackException::what() const throw()
{
	return ("PopOnEmptyStackException: Try to pop on an empty stack!");
}

const char *	Exception::FloatingPointException::what() const throw()
{
	return ("FloatingPointException: Division/Modulo by 0!");
}

const char *	Exception::MissingExitInstructionException::what() const throw()
{
	return ("MissingExitInstructionException: Missing exit instruction!");
}

const char *	Exception::AssertException::what() const throw()
{
	return ("AssertException: Assert instruction is not true!");
}

const char *	Exception::OperationOnEmptyStackException::what() const throw()
{
	return ("OperationOnEmptyStackException: Operation failed because the stack had less than two operands!");
}

const char *	Exception::ModuloOnFloatingPointException::what() const throw()
{
	return ("ModuloOnFloatingPointException: Modulo impossible on floating point!");
}

const char *	Exception::PrintNonAsciiException::what() const throw()
{
	return ("PrintNonAsciiException: Impossible to print non ascii character!");
}

const char *	Exception::PrintOnEmptyStackException::what() const throw()
{
	return ("PrintOnEmptyStackException: Impossible to print on empty stack!");
}

const char *	Exception::FileDoesNotExistException::what() const throw()
{
	return ("FileDoesNotExistException: File doesn't exist!");
}