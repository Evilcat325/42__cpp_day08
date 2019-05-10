#include "MindOpen.hpp"

#include <iostream>
#include <string>

int main()
{
	// MindOpen::verbose = true;
	std::string cmd;
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "exit")
			return 0;
		else
		{
			std::string extension = cmd.substr(cmd.find_first_of(".") + 1);
			if (extension == "bf")
				MindOpen::cmds = "><+-.,[]";
			else if (extension == "mo")
				MindOpen::cmds = "<>-+,.][";
			else
			{
				std::cerr << "not supported file " << cmd << std::endl;
				continue;
			}
			MindOpen mo;
			if (!mo.parse(cmd))
			{
				std::cerr << "error opening " << cmd << std::endl;
				continue;
			}
			mo.exec();
			std::cout << std::endl;
		}
	}
	return 0;
}
