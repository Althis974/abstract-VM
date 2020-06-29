/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlossy <rlossy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 09:58:11 by rlossy            #+#    #+#             */
/*   Updated: 2020/06/29 09:58:11 by rlossy           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "IOperand.hpp"
#include "Exception.hpp"
#include "Computer.hpp"

template <typename T>
class Operand : public IOperand
{

public:

		// Constructors
		Operand() = default;
		Operand(const eOperandType type, const T value) : _type(type),
				_value(value)
		{
			setRepresentation();
		};

		// Copy constructor
		Operand(const Operand &src) = default;

		// Destructor
		virtual ~Operand()
		{
			delete this->_representation;
		};

		// Assignation operator overload
		Operand & 				operator=(const Operand &rhs) = default;

		// Setters
		void 					setRepresentation()
		{
			this->_representation = new std::string();
			std::ostringstream	oStringStream;

			if (this->_type == INT8)
				oStringStream << static_cast<int>(this->_value);
			else
				oStringStream << this->_value;

			this->_representation->append(oStringStream.str());
		}

		// Getters
		eOperandType			getType() const
		{
			return (this->_type);
		};

		int						getPrecision() const
		{
			return (this->_type);
		};

		T						getValue() const
		{
			return (this->_value);
		};

		// Explicit
		std::string const & 	toString() const
		{
			return (*this->_representation);
		};

		// Arithmetic operators overload
		IOperand const * 		operator+(const IOperand &rhs) const
		{
			int					i = 0;
			double 				d = 0;
			eOperandType 		type;
			const Operand<T> *	op = nullptr;

			if (this->_type == rhs.getPrecision())
			{
				op = static_cast<const Operand<T> *>(&rhs);

				return (new Operand<T>(this->_type, op->getValue() + this->_value));
			}
			else
			{
				if (this->_type > rhs.getPrecision())
					type = _type;
				else
					type = rhs.getType();

				switch (type)
				{
					case INT8:
					case INT16:
					case INT32:
						i = std::stoi(rhs.toString()) + this->_value;
						break ;

					case FLOAT:
					case DOUBLE:
						d = std::stod(rhs.toString()) + this->_value;
						break ;

					case UNKNOWN:
						break ;
				}

			return (this->_computer.createOperand(type, std::to_string((i) ? i : d)));
			}

			return (nullptr);
		}

		IOperand const * 		operator-(const IOperand &rhs) const
		{
			int					i = 0;
			double 				d = 0;
			eOperandType 		type;
			const Operand<T> *	op = nullptr;

			if (this->_type == rhs.getPrecision())
			{
				op = static_cast<const Operand<T> *>(&rhs);

				return (new Operand<T>(this->_type, op->getValue() - this->_value));
			}

			else
			{
				if (this->_type > rhs.getPrecision())
					type = this->_type;
				else
					type = rhs.getType();

				switch (type)
				{
					case INT8:
					case INT16:
					case INT32:
						i = std::stoi(rhs.toString()) - this->_value;
						break ;

					case FLOAT:
					case DOUBLE:
						d = std::stod(rhs.toString()) - this->_value;
						break ;

					case UNKNOWN:
						break ;
				}

				return (this->_computer.createOperand(type, std::to_string((i) ? i : d)));
			}

			return (nullptr);
		}

		IOperand const *		operator*(const IOperand &rhs) const
		{
			int					i = 0;
			double 				d = 0;
			eOperandType 		type;
			const Operand<T> *	op = nullptr;

			if (this->_type == rhs.getPrecision())
			{
				op = static_cast<const Operand<T> *>(&rhs);

				return (new Operand<T>(this->_type, op->getValue() * this->_value));
			}
			else
			{
				if (this->_type > rhs.getPrecision())
					type = this->_type;
				else
					type = rhs.getType();

				switch (type)
				{
					case INT8:
					case INT16:
					case INT32:
						i = std::stoi(rhs.toString()) * this->_value;
						break ;

					case FLOAT:
					case DOUBLE:
						d = std::stod(rhs.toString()) * this->_value;
						break ;

					case UNKNOWN:
						break ;
				}

				return (this->_computer.createOperand(type, std::to_string((i) ? i : d)));
			}

			return (nullptr);
		}

		IOperand const *		operator/(const IOperand &rhs) const
		{
			int					i = 0;
			double 				d = 0;
			eOperandType 		type;
			const Operand<T> *	op = nullptr;

			if (this->_type == rhs.getPrecision())
			{
				if (!this->_value)
					throw Exception::FloatingPointException();
				
				op = static_cast<const Operand<T> *>(&rhs);

				return (new Operand<T>(this->_type, op->getValue() / this->_value));
			}
			else
			{
				if (!this->_value)
					throw Exception::FloatingPointException();

				if (this->_type > rhs.getPrecision())
					type = this->_type;
				else
					type = rhs.getType();

				switch (type)
				{
					case INT8:
					case INT16:
					case INT32:
						i = std::stoi(rhs.toString()) / this->_value;
						break ;

					case FLOAT:
					case DOUBLE:
						d = std::stod(rhs.toString()) / this->_value;
						break ;

					case UNKNOWN:
						break ;
				}

				return (this->_computer.createOperand(type, std::to_string((i) ? i : d)));
			}

			return (nullptr);
		}

		IOperand const *		operator%(const IOperand &rhs) const
		{
			int					i = 0;
			long int			d = 0;
			eOperandType 		type;
			const Operand<T> *	op = nullptr;

			if (this->_type == rhs.getPrecision())
			{
				if (!this->_value)
					throw Exception::FloatingPointException();

				op = static_cast<const Operand<T> *>(&rhs);

				return (new Operand<T>(this->_type, static_cast<long int>(op->getValue()) % static_cast<long int>(this->_value)));
			}
			else
			{
				if (!this->_value)
					throw Exception::FloatingPointException();

				if (this->_type > rhs.getPrecision())
					type = this->_type;
				else
					type = rhs.getType();

				switch (type)
				{
					case INT8:
					case INT16:
					case INT32:
						i = static_cast<long int>(std::stoi(rhs.toString())) % static_cast<long int>(this->_value);
						break ;

					case FLOAT:
					case DOUBLE:
						throw Exception::ModuloOnFloatingPointException();

					case UNKNOWN:
						break ;
				}

				return (this->_computer.createOperand(type, std::to_string((i) ? i : d)));
			}

			return (nullptr);
		}

private:

		const eOperandType		_type;
		T						_value;
		std::string * 			_representation;
		Computer				_computer;
};

#endif
