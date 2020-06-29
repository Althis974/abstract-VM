/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlossy <rlossy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 09:59:42 by rlossy            #+#    #+#             */
/*   Updated: 2020/06/29 09:59:42 by rlossy           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>
#include <exception>

namespace Exception
{
	class OverflowException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class UnderflowException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class SyntaxException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class UnknownInstructionException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class PopOnEmptyStackException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class FloatingPointException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class MissingExitInstructionException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class AssertException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class OperationOnEmptyStackException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class ModuloOnFloatingPointException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class PrintNonAsciiException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class PrintOnEmptyStackException: public std::exception
	{

	public:

			const char *	what() const throw();
	};

	class FileDoesNotExistException: public std::exception
	{

	public:

			const char *	what() const throw();
	};
};

#endif
