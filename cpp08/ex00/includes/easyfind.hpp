#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>
#include <vector>
#include <list>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"


class NotFoundException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return "Value not found in the container.";
		}
};

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
	typename T::const_iterator it;
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}
#endif // easyfind_HPP
