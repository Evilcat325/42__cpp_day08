#ifndef FT_TOKEN_HPP
#define FT_TOKEN_HPP

#include <string>
#include <iostream>
#include <sstream>

enum TokenType
{
	NUMBER,
	OPERATION,
	PAROPEN,
	PARCLOSE
};

class Token
{

public:
	Token(int number);
	Token(char op);
	Token(bool open);
	~Token();
	Token(Token const &rhs);
	Token &operator=(Token const &rhs);
	union data {
		data(int nbr) : nbr(nbr) {}
		data(char op) : op(op) {}
		data(bool open) : open(open) {}
		int nbr;
		char op;
		bool open;
	};

protected:
	TokenType const type;
	data value;

public:
	TokenType getType() const;
	Token::data getValue() const;
	int getPrec() const;
	std::string getOpName() const;
};

std::ostream &operator<<(std::ostream &out, Token &rhs);

#endif /* FT_Token_HPP */
