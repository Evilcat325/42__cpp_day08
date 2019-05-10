#include "span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	Span sp = Span(5);
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(5);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	sp.addNumber(5);
	sp.addNumber(100);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(5);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------" << std::endl;
	std::vector<int> v(10000);
	for (std::vector<int>::iterator it = v.begin(), end = v.end();
			 it < end; ++it)
	{
		*it = rand() % 10000;
	}
	Span test(10000);
	test.addNumber(5);
	try
	{
		test.addNumber(v.begin(), v.end());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	test.addNumber(v.begin(), v.end() - 5);
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
	return 0;
}
