#ifndef FT_MUTANTSTACK_HPP
#define FT_MUTANTSTACK_HPP

#include <stack>

// assuming default deque<T> as the container for stack
// would break if underlying container don't have iter
template <class T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type container_type;
	typedef typename container_type::iterator iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};

#endif /* FT_mutantstack_HPP */
