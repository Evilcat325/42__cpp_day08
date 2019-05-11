#ifndef FT_MUTANTSTACK_HPP
#define FT_MUTANTSTACK_HPP

#include <stack>
#include <iostream>

// assuming default deque<T> as the container for stack
// would break if underlying container don't have iter
template <class T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type container_type;
	typedef typename container_type::iterator iterator;
	typedef typename container_type::reverse_iterator reverse_iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}
	reverse_iterator rend()
	{
		return this->c.rend();
	}
	void print()
	{
		for (reverse_iterator it = this->rbegin(), end = this->rend(); it != end; ++it)
		{
			if (it != this->rbegin())
				std::cout << " ";
			std::cout << *it;
		}
	}
};

#endif /* FT_mutantstack_HPP */
