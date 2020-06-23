//
// Created by Romeo on 22/06/2020.
//

#include "../includes/Exception.hpp"

// Constructor

Exception::Exception(const std::string &reason) : _reason(reason)
{

}

// Returns a pointer to the error description

const char * 	Exception::what() const throw()
{
	return (this->_reason.c_str());
}