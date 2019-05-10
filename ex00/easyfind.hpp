#ifndef FT_EASYFIND_HPP
#define FT_EASYFIND_HPP

#include <iostream>
#include <typeinfo>

template <typename T>
int easyfind(T list, int needle)
{

	for (int i = 0, e = list.size(); i < e; i++)
		if (list[i] == needle)
			return i;
	return -1;
}

#endif /* FT_easyfind_HPP */
