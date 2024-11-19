/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:12:24 by ecarlier          #+#    #+#             */
/*   Updated: 2024/11/19 21:17:46 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() :  _N(0)
{
	#ifdef DEBUG_MODE
		std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
	#endif

}

Span::Span(unsigned int N) : _N(N)
{
	#ifdef DEBUG_MODE
		std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
	#endif

}

Span::~Span()
{
	#ifdef DEBUG_MODE
		std::cout << "\033[32m" << "Destructor called" << "\033[0m" << std::endl;
	#endif

}

Span::Span(const Span &copy) : _N(copy._N), _vec(copy._vec)
{
	#ifdef DEBUG_MODE
		std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	#endif

}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy) {
		this->_N = copy._N;
		this->_vec = copy._vec;
	}
	#ifdef DEBUG_MODE
	std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	#endif

	return *this;
}


void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int count = std::distance(begin, end);
	if (_vec.size() + count > _N)
		throw Span::Spanfull();
	_vec.insert(_vec.end(), begin, end);
}

/*
	add a single number to the Span
	Any attempt to add a new element if there are already N elements stored should throw an exceptio
*/
void Span::addNumber(int n)
{
	if (this->_vec.size() >= this->_N)
		throw Span::Spanfull();
	this->_vec.push_back(n);
}

void	Span::checkElement()
{
	if (this->_vec.empty())
		throw Span::NoElement();
	if (this->_vec.size() == 1)
		throw Span::OnlyOneElement();
}

int Span::shortestSpan()
{
	try
	{
		checkElement();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return -1;
	}
	std::vector<int> temp = this->_vec; //temporary sorted vector
	std::sort(temp.begin(), temp.end());
	int shortest = INT_MAX;
	for (size_t i = 0; i < temp.size() - 1; ++i)
	{
		int span = temp[i + 1] - temp[i];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}


int Span::longestSpan()
{
	try
	{
		checkElement();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return -1;
	}
	std::vector<int> temp = this->_vec; //temporary sorted vector
	std::sort(temp.begin(), temp.end());

	int longest = temp.back() - temp.front();

	return longest;
}



const char*	Span::Spanfull::what() const throw()
{
	return ("Throwing execption : Span full, cannot add any more element.");
}

const char*	Span::NoElement::what() const throw()
{
	return ("Throwing execption : Span empty.");
}

const char*	Span::OnlyOneElement::what() const throw()
{
	return ("Throwing execption : span not big enough, only one element.");
}

const char*	Span::NoSpanFound::what() const throw()
{
	return ("Throwing execption : no span found.");
}

const std::vector<int>& Span::getVector() const
{
        return _vec;
}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
    const std::vector<int>& vec = span.getVector(); // Utilise le getter

    if (vec.empty()) {
        os << "Span is empty.";
        return os;
    }

    os << "[ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << ", ";
        }
    }
    os << " ]";
    return os;
}

