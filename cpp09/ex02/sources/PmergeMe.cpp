/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:20:11 by ecarlier          #+#    #+#             */
/*   Updated: 2024/12/03 16:15:57 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
}


PmergeMe::PmergeMe(const std::vector<int> &vector, const std::deque<int> &deque)
{

    _vec = vector;
    _deq = deque;




    printVector(1);
    printDeque(1);

	sort_vector();

	printVector(0);
	printDeque(0);

}

PmergeMe::~PmergeMe()
{
	//std::cout << "\033[32m" << "Destructor called" << "\033[0m" << std::endl;
}


PmergeMe::PmergeMe(const PmergeMe &copy)
{
    this->_vec = copy._vec;
    this->_deq = copy._deq;
}


PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		this->_vec = copy._vec;
		this->_deq = copy._deq;
	}
	return *this;
}

/*
Determine the larger of the two pairs in each pair and puts it on the front
*/
template <typename Container>
Container sortPairs(Container pairs)
{
	typename Container::iterator it;
	for (it = pairs.begin(); it != pairs.end(); it++)
	{
		if ((*it).first < (*it).second && (*it).first != -1)
			std::swap((*it).first, (*it).second);
	}
	return pairs;
}

// std::vector<std::pair<int, int>> PmergeMe::sortPairs(std::vector<std::pair<int, int>> pairs)
// {
// 	std::vector<std::pair<int, int> >::iterator	it;
// 	for (it = pairs.begin(); it != pairs.end(); it++)
// 	{
// 		if ((*it).first < (*it).second && (*it).first != -1)
// 			std::swap((*it).first, (*it).second);
// 	}
// 	return pairs;
// }

/*
Group the elements of X into [n/2] pairs of elements -> if oddm leave the last element unpair
Put the larger one of the pair on the front
recursively sort the [n/2] larger elements from each pair
*/
void PmergeMe::sort_vector()
{
	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>::iterator			it;

	#ifdef DEBUG_MODE
		std::cout << CYAN << "Sorting vector..." << RESET << std::endl;
	#endif

	for (it = this->_vec.begin(); it != this->_vec.end() && it + 1 != this->_vec.end() ; it += 2)
	{
		if (it + 1 != this->_vec.end())
		{
			std::pair<int, int>	p(*it, *(it + 1));
			pairs.push_back(p);
		}
		else if (it + 1 == this->_vec.end())
		{
			std::pair<int, int>	p(-1, *(it));
			pairs.push_back(p);
		}
	}

	pairs = sortPairs(pairs);

}

void PmergeMe::sort_deque()
{
	std::deque<std::pair<int, int> >	pairs;
	std::deque<int>::iterator			it;

	for (it = this->_deq.begin(); it != this->_deq.end() && it + 1 != this->_deq.end() ; it += 2)
	{
		if (it + 1 != this->_deq.end())
		{
			std::pair<int, int>	p(*it, *(it + 1));
			pairs.push_back(p);
		}
		else if (it + 1 == this->_deq.end())
		{
			std::pair<int, int>	p(-1, *(it));
			pairs.push_back(p);
		}
	}

	pairs = sortPairs(pairs);

}

void PmergeMe::printVector(bool is_before)
{
	if (is_before)
		std::cout << "Vector "  << "before:\t";
	else
		std::cout << "Vector "<< "after:\t";

	std::vector<int>::const_iterator it;
	for (it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printDeque(bool is_before)
{
	if (is_before)
		std::cout << "Deque " << " before:\t" ;
	else
		std::cout << "Deque "  << " after:\t";

	std::deque<int>::const_iterator it;
	for (it = _deq.begin(); it != _deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

double PmergeMe::getVectorSortingTime()
{
	return _vectorSortingTime;
}

double PmergeMe::getDequeSortingTime()
{
	return _dequeSortingTime;
}



int getMidPoint(int start, int end) {
	return(start + (end - start) / 2);
}
