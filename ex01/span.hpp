#ifndef FT_SPAN_HPP
#define FT_SPAN_HPP

#include <set>
#include <limits>
#include <iostream>

class Span
{
private:
	unsigned int const size;
	std::multiset<int> s;

public:
	struct NotEnoughNumber : public std::exception
	{
		const char *what() const throw()
		{
			return "Not enough number to calculate Span";
		}
	};
	struct SpanFull : public std::exception
	{
		const char *what() const throw()
		{
			return "SpanFull";
		}
	};
	struct SpanNotEnoughSpace : public std::exception
	{
		const char *what() const throw()
		{
			return "Span Not Enough Space Left";
		}
	};
	Span(unsigned int n);
	~Span();
	Span(Span const &rhs);
	Span &operator=(Span const &rhs);
	void addNumber(int num);
	template <class Iter>
	void addNumber(Iter begin, Iter end);
	int shortestSpan() const;
	int longestSpan() const;
};

template <class Iter>
void Span::addNumber(Iter begin, Iter end)
{
	int num = std::distance(begin, end);
	if (s.size() + num > size)
		throw SpanNotEnoughSpace();
	for (; begin < end; ++begin)
		s.insert(*begin);
}

#endif /* FT_span_HPP */
