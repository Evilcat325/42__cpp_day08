#ifndef FT_TOKENIZER_HPP
#define FT_TOKENIZER_HPP

#include <queue>
#include <sstream>
#include <iostream>
#include <stack>
#include "Token.hpp"

class Tokenizer
{
private:
	std::queue<Token> infix_queue;
	std::queue<Token> postfix_queue;

public:
	Tokenizer();
	~Tokenizer();
	Tokenizer(Tokenizer const &rhs);
	Tokenizer &operator=(Tokenizer const &rhs);
	bool parse(std::string &infix);
	void toPostfix();
	void print_postfix();
	void print_infix();
	std::queue<Token> getPostfix() const;

private:
	bool isOperation(char &c);
	void print_queue(std::queue<Token> &q);
};

#endif /* FT_Tokenizer_HPP */
