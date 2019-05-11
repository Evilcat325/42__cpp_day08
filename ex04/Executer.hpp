#ifndef FT_EXECUTER_HPP
#define FT_EXECUTER_HPP

#include <queue>
#include <iomanip>
#include "Token.hpp"
#include "mutantstack.hpp"

class Executer
{
private:
	std::queue<Token> q;

public:
	Executer(std::queue<Token> postfix_queue);
	~Executer();
	Executer(Executer const &rhs);
	Executer &operator=(Executer const &rhs);
	bool exec();
};

#endif /* FT_Executer_HPP */
