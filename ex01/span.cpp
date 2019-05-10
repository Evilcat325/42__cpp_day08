#include "span.hpp"

Span::Span(unsigned int n)
		: size(n)
{
}

Span::~Span()
{
}

Span::Span(Span const &rhs)
		: size(rhs.size)
{
	*this = rhs;
}

Span &Span::operator=(Span const &rhs)
{
	s = rhs.s;
	return *this;
}

void Span::addNumber(int number)
{
	if (s.size() == size)
		throw SpanFull();
	else
		s.insert(number);
}

int Span::shortestSpan() const
{
	if (s.size() <= 1)
		throw NotEnoughNumber();
	int min = std::numeric_limits<int>::max();
	std::multiset<int>::iterator it = s.begin(), end = s.end();
	--end;
	while (it != end)
	{
		int cur = *it;
		it++;
		min = std::min(min, std::abs(cur - *it));
	}
	return min;
}

int Span::longestSpan() const
{
	if (s.size() <= 1)
		throw NotEnoughNumber();
	return std::abs(*(--s.end()) - *s.begin());
}
