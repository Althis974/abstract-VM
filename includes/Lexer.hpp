/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlossy <rlossy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 09:58:52 by rlossy            #+#    #+#             */
/*   Updated: 2020/06/29 09:58:52 by rlossy           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <regex>
#include "Operand.hpp"

enum eInstructionType
{
	PUSH,
	POP,
	DUMP,
	ASSERT,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	PRINT,
	EXIT,
	COMMENT,
	END,
	ERROR
};

namespace Lexer
{
	eInstructionType	getInstructionType(const std::string &s);
	eOperandType		getOperandType(const std::string &s);
	std::string			getOperandValue(const std::string &s);
};


#endif
