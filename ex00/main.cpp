#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <unordered_set>
#include <queue>

template <class T>
void test(T &list, int target)
{
	typename T::iterator ret = easyfind(list, target);
	if (ret != list.end())
	{
		std::cout << "Found" << std::endl;
	}
	else
		std::cout << "Not found" << std::endl;
}

int main()
{
	//Sequence Containers
	std::vector<int> vectors;
	std::list<int> lists;
	// queue doesn't work as it limit the interface to push and pop only
	// save with stack or `Container Adaptors`
	std::queue<int> queues;

	// it still works on `Associative Containers` as they have a iterator
	std::set<int> sets;
	for (int i = 0; i < 10; i++)
	{
		vectors.push_back(i);
		lists.push_back(i);
		//queues.push(i);
		sets.insert(i);
	}
	test(vectors, 0);
	test(vectors, 3);
	test(vectors, 6);
	test(vectors, 12);
	test(lists, 3);
	test(lists, 11);
	// test(queues, 2);
	// test(queues, 13);
	test(sets, 1);
	test(sets, 32767);
	return 0;
}
