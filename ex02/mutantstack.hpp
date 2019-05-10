#ifndef FT_MUTANTSTACK_HPP
#define FT_MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	auto begin()
	{
		return this->c.begin();
	}
	auto end()
	{
		return this->c.end();
	}
};

#endif /* FT_mutantstack_HPP */
