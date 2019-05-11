#include "Tokenizer.hpp"

Tokenizer::Tokenizer()
{
}

Tokenizer::~Tokenizer()
{
}

Tokenizer::Tokenizer(Tokenizer const &rhs)
{
	*this = rhs;
}

Tokenizer &Tokenizer::operator=(Tokenizer const &)
{
	return *this;
}

bool Tokenizer::parse(std::string &infix)
{
	std::stringstream sin(infix);
	int number;
	char op;
	while (!sin.eof())
		if (std::isdigit(sin.peek()))
		{
			sin >> number;
			infix_queue.push(Token(number));
		}
		else
		{
			sin.get(op);
			if (op == ' ' || op == '\t')
				continue;
			if (op == '(' || op == ')')
				infix_queue.push(Token(op == '('));
			else if (isOperation(op))
				infix_queue.push(Token(op));
			else
				return false;
		}
	return true;
}

bool Tokenizer::isOperation(char &c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void Tokenizer::toPostfix()
{
	std::stack<Token> op_st;
	while (!infix_queue.empty())
	{
		Token t = infix_queue.front();
		infix_queue.pop();
		if (t.getType() == NUMBER)
			postfix_queue.push(t);
		else if (t.getType() == PAROPEN)
			op_st.push(t);
		else if (t.getType() == PARCLOSE)
		{
			while (!op_st.empty() && op_st.top().getType() != PAROPEN)
			{
				postfix_queue.push(op_st.top());
				op_st.pop();
			}
			if (op_st.top().getType() == PAROPEN)
				op_st.pop();
		}
		else
		{
			while (!op_st.empty() && t.getPrec() <= op_st.top().getPrec())
			{
				postfix_queue.push(op_st.top());
				op_st.pop();
			}
			op_st.push(t);
		}
	}
	while (!op_st.empty())
	{
		postfix_queue.push(op_st.top());
		op_st.pop();
	}
}

void Tokenizer::print_postfix()
{
	std::cout << "Postfix: ";
	print_queue(postfix_queue);
}

void Tokenizer::print_infix()
{
	std::cout << "Tokens: ";
	print_queue(infix_queue);
}

void Tokenizer::print_queue(std::queue<Token> &q)
{
	for (int i = 0, e = q.size(); i < e; ++i)
	{
		Token t = q.front();
		q.pop();
		q.push(t);
		std::cout << t << " ";
	}
	std::cout << std::endl;
}

std::queue<Token> Tokenizer::getPostfix() const
{
	return postfix_queue;
}
