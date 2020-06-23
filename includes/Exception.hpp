//
// Created by Romeo on 22/06/2020.
//

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>
#include <exception>

class Exception : public std::exception
{

public:

		// Constructors
		Exception();
		Exception(const std::string &reason);

		// Copy constructor
		Exception(const Exception &src) = default;

		// Destructor
		virtual ~Exception() throw() = default;

		// Assignation operator overload
		Exception & operator=(const Exception &rhs) = default;

		// Returns a pointer to the error description
		const char *	what() const throw();

private:

		std::string   	_reason;
};


#endif
