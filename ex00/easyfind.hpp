#ifndef FT_EASYFIND_HPP
#define FT_EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <class T, class U>
typename T::iterator easyfind(T &list, U value)
{
	return std::find(list.begin(), list.end(), value);
}
#endif /* FT_easyfind_HPP */
