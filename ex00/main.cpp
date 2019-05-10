#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> ints(10, 5);
	std::cout << easyfind(ints, 5) << std::endl;
	return 0;
}
