#include <string>
#include <stack>
#include <iostream>
#include "Tokenizer.hpp"
#include "Executer.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "expecting only one argument" << std::endl;
		return 0;
	}
	Tokenizer parser;
	std::string input = argv[1];
	if (!parser.parse(input))
	{
		std::cerr << "invalid token" << std::endl;
		return 0;
	}
	parser.print_infix();
	parser.toPostfix();
	parser.print_postfix();
	Executer exec(parser.getPostfix());
	exec.exec();
	return 0;
}
