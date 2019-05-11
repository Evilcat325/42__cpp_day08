#include "Token.hpp"

Token::Token(int number)
		: type(NUMBER), value(number)
{
}

Token::Token(char op)
		: type(OPERATION), value(op)
{
}

Token::Token(bool open)
		: type(open ? PAROPEN : PARCLOSE), value(open)
{
}

Token::~Token()
{
}

Token::Token(Token const &rhs)
		: type(rhs.type), value(rhs.value)
{
	*this = rhs;
}

Token &Token::operator=(Token const &rhs)
{
	value = rhs.value;
	return *this;
}

TokenType Token::getType() const
{
	return type;
}

Token::data Token::getValue() const
{
	return value;
}

int Token::getPrec() const
{
	if (type == OPERATION)
	{
		if (value.op == '*' || value.op == '/')
			return 2;
		else if (value.op == '+' || value.op == '-')
			return 1;
	}

	return -1;
}

std::string Token::getOpName() const
{
	if (type == NUMBER)
		return "Push";
	switch (value.op)
	{
	case '+':
		return "Add";
	case '-':
		return "Substract";
	case '*':
		return "Multiply";
	case '/':
		return "Divide";
	default:
		return "";
	}
}

std::ostream &operator<<(std::ostream &out, Token &rhs)
{
	switch (rhs.getType())
	{
	case NUMBER:
	{
		std::stringstream ss;
		ss << "Num(" << rhs.getValue().nbr << ")";
		out << ss.str();
		break;
	}
	case OPERATION:
	{
		std::stringstream ss;
		ss << "Op(" << rhs.getValue().op << ")";
		out << ss.str();
		break;
	}
	case PAROPEN:
		out << "ParOpen";
		break;
	case PARCLOSE:
		out << "ParClose";
		break;
	default:
		break;
	};
	return out;
}
