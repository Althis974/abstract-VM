//
// Created by Romeo on 22/06/2020.
//

#include "../includes/Exception.hpp"

const char *	Exception::OverflowException::what() const throw()
{
	return ("Exception: OverflowException on a value!");
}

const char *	Exception::UnderflowException::what() const throw()
{
	return ("Exception: Underflow on a value!");
}

const char *	Exception::SyntaxException::what() const throw()
{
	return ("Exception: Syntax error!");
}

const char *	Exception::UnknownInstructionException::what() const throw()
{
	return ("Exception: Unknown instruction!");
}

const char *	Exception::PopOnEmptyStackException::what() const throw()
{
	return ("Exception: Try to pop on an empty stack!");
}

const char *	Exception::FloatingPointException::what() const throw()
{
	return ("Exception: Division/Modulo by 0!");
}

const char *	Exception::MissingExitInstructionException::what() const throw()
{
	return ("Exception: Missing exit instruction!");
}

const char *	Exception::AssertException::what() const throw()
{
	return ("Exception: Assert instruction is not true!");
}

const char *	Exception::OperationOnEmptyStackException::what() const throw()
{
	return ("Exception: Operation failed because the stack had less than two operands!");
}

const char *	Exception::ModuloOnFloatingPointException::what() const throw()
{
	return ("Exception: Modulo impossible on floating point!");
}

const char *	Exception::PrintNonAsciiException::what() const throw()
{
	return ("Exception: Impossible to print non ascii character!");
}

const char *	Exception::PrintOnEmptyStackException::what() const throw()
{
	return ("Exception: Impossible to print on empty stack!");
}

const char *	Exception::FileDoesNotExistException::what() const throw()
{
	return ("Exception: File doesn't exist!");
}