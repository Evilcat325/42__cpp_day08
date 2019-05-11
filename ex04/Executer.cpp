#include "Executer.hpp"

Executer::Executer(std::queue<Token> postfix_queue)
		: q(postfix_queue)
{
}

Executer::~Executer()
{
}

Executer::Executer(Executer const &rhs)
		: q(rhs.q)
{
	*this = rhs;
}

Executer &Executer::operator=(Executer const &rhs)
{
	q = rhs.q;
	return *this;
}

bool Executer::exec()
{
	MutantStack<double> st;
	while (!q.empty())
	{
		Token t = q.front();
		q.pop();
		if (t.getType() == NUMBER)
			st.push(t.getValue().nbr);
		else
		{
			if (st.size() < 2)
				return false;
			double rhs = st.top();
			st.pop();
			double lhs = st.top();
			st.pop();
			switch (t.getValue().op)
			{
			case '+':
				st.push(lhs + rhs);
				break;
			case '-':
				st.push(lhs - rhs);
				break;
			case '*':
				st.push(lhs * rhs);
				break;
			case '/':
				st.push(lhs / rhs);
				break;
			default:
				return false;
			}
		}
		std::cout << "I " << std::setw(7)
							<< std::setiosflags(std::ios::left) << t << " | OP "
							<< std::setw(9) << t.getOpName() << " | ST ";
		st.print();
		std::cout << "]" << std::endl;
	}
	std::cout << "Result : " << st.top() << std::endl;
	return true;
}
