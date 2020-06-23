//
// Created by Romeo on 19/06/2020.
//

#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "IOperand.hpp"
#include "Exception.hpp"

typedef struct			s_operand
{
	eOperandType		type;
	std::string			name;
	int					precision;
	long				min;
	long				max;
}						t_operand;

static t_operand 		operands[] =
{
		{INT8, "int8", 0 , -128, 127},
		{INT16, "int16", 1, -32768, 32767},
		{INT32, "int32", 2, -2147483648, 2147483647},
		{FLOAT, "float", 3, -32768, 32767},
		{DOUBLE, "double", 4, -2147483648, 2147483647},
};

template <typename T>
class 	Operand : public IOperand
{

public:

		// Constructors
		explicit Operand()
		{
			this->_value = static_cast<T>(0);
		}

		explicit Operand(eOperandType type, const double &value)
		{
			this->_type = type;
			if (value < operands[type].max)
			{
				if (value > operands[type].min)
					this->_precision = operands[type].precision;
				else
					throw Exception("Underflow.");
			}
			else
				throw Exception("Overflow.");
			this->_value = value;
		}

		// Copy constructor
		Operand(const Operand &src) = default;

		// Destructor
		virtual ~Operand() = default;

		// Assignation operator overload
		Operand & operator=(const Operand &rhs) = default;

		virtual std::string const &	toString() const
		{
			std::string *s = new std::string();
			std::ostringstream oStringStream;

			if (this->_type == INT8)
				oStringStream << static_cast<int>(this->_value);
			else
				oStringStream << this->_value;
			s->append(oStringStream.str());

			return (*s);
		}

		// Getters
		virtual int					getPrecision() const
		{
			return (this->_precision);
		}

		virtual eOperandType		getType() const
		{
			return (this->_type);
		}

		virtual T					getValue() const
		{
			return (this->_value);
		}

		virtual IOperand *			operator+(const IOperand &rhs) const
		{
			IOperand		*operand = NULL;
			eOperandType	type;

			type = this->_precision >= rhs.getPrecision() ? this->_type : rhs.getType();
			switch (type)
			{
				case INT8:
					operand = new Operand<char>(type, this->_value + ft_atof(rhs.toString()));
					break;
				case INT16:
					operand = new Operand<short>(type, this->_value + ft_atof(rhs.toString()));
					break;
				case INT32:
					operand = new Operand<int>(type, this->_value + ft_atof(rhs.toString()));
					break;
				case FLOAT:
					operand = new Operand<float>(type, this->_value + ft_atof(rhs.toString()));
					break;
				case DOUBLE:
					operand = new Operand<double>(type, this->_value + ft_atof(rhs.toString()));
					break;
			}

			return (operand);
		}

		virtual IOperand *			operator-(const IOperand &rhs) const
		{
			IOperand		*operand = NULL;
			eOperandType	type;

			type = this->_precision >= rhs.getPrecision() ? this->_type : rhs.getType();
			switch (type)
			{
				case INT8:
					operand = new Operand<char>(type, this->_value - ft_atof(rhs.toString()));
					break;
				case INT16:
					operand = new Operand<short>(type, this->_value - ft_atof(rhs.toString()));
					break;
				case INT32:
					operand = new Operand<int>(type, this->_value - ft_atof(rhs.toString()));
					break;
				case FLOAT:
					operand = new Operand<float>(type, this->_value - ft_atof(rhs.toString()));
					break;
				case DOUBLE:
					operand = new Operand<double>(type, this->_value - ft_atof(rhs.toString()));
					break;
			}

			return (operand);
		}

		virtual IOperand *			operator*(const IOperand &rhs) const
		{
			IOperand		*operand = NULL;
			eOperandType	type;

			type = this->_precision >= rhs.getPrecision() ? this->_type : rhs.getType();
			switch (type)
			{
				case INT8:
					operand = new Operand<char>(type, this->_value * ft_atof(rhs.toString()));
					break;
				case INT16:
					operand = new Operand<short>(type, this->_value * ft_atof(rhs.toString()));
					break;
				case INT32:
					operand = new Operand<int>(type, this->_value * ft_atof(rhs.toString()));
					break;
				case FLOAT:
					operand = new Operand<float>(type, this->_value * ft_atof(rhs.toString()));
					break;
				case DOUBLE:
					operand = new Operand<double>(type, this->_value * ft_atof(rhs.toString()));
					break;
			}

			return (operand);
		}

		virtual IOperand *			operator/(const IOperand &rhs) const
		{
			IOperand		*operand = NULL;
			eOperandType	type;
			const Operand	&tmp = static_cast<const Operand &>(rhs);

			if (!ft_atof(tmp.toString()))
				throw Exception("Division by zero.");

			type = this->_precision >= rhs.getPrecision() ? this->_type : rhs.getType();
			switch (type)
			{
				case INT8:
					operand = new Operand<char>(type, this->_value / ft_atof(rhs.toString()));
					break;
				case INT16:
					operand = new Operand<short>(type, this->_value / ft_atof(rhs.toString()));
					break;
				case INT32:
					operand = new Operand<int>(type, this->_value / ft_atof(rhs.toString()));
					break;
				case FLOAT:
					operand = new Operand<float>(type, this->_value / ft_atof(rhs.toString()));
					break;
				case DOUBLE:
					operand = new Operand<double>(type, this->_value / ft_atof(rhs.toString()));
					break;
			}

			return (operand);
		}

		virtual IOperand *			operator%(const IOperand &rhs) const
		{
			IOperand		*operand = NULL;
			eOperandType	type;
			const Operand	&tmp = static_cast<const Operand &>(rhs);

			if (!ft_atof(tmp.toString()))
				throw Exception("Modulo by zero.");

			type = this->_precision >= rhs.getPrecision() ? this->_type : rhs.getType();
			if (this->_type == FLOAT || rhs.getType() == FLOAT)
				throw Exception("Modulo with float.");
			else if (this->_type == DOUBLE || rhs.getType() == DOUBLE)
				throw Exception("Modulo with double.");
			operand = new Operand(type, static_cast<int>(this->_value) % ft_atoi(tmp.toString()));

			return (operand);
		}

		std::ostream &				operator<<(std::ostream &out)
		{
			out << this->getValue();

			return (out);
		}

private:

		eOperandType	_type;
		int				_precision;
		T				_value;
};

#endif
