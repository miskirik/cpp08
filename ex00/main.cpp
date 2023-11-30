#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		l.push_back(i);
		d.push_back(i);
	}

	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "List: ";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Deque: ";
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Searching for 5 in vector: ";
	try
	{
		std::vector<int>::iterator it = easyfind(v, 5);
		std::cout << "Found " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Searching for 5 in list: ";
	try
	{
		std::list<int>::iterator it = easyfind(l, 5);
		std::cout << "Found " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Searching for 5 in deque: ";
	try
	{
		std::deque<int>::iterator it = easyfind(d, 5);
		std::cout << "Found " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Searching for 42 in vector: ";
	try
	{
		std::vector<int>::iterator it = easyfind(v, 42);
		std::cout << "Found " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}