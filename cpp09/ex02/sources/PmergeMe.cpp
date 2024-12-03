/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:20:11 by ecarlier          #+#    #+#             */
/*   Updated: 2024/12/03 22:09:59 by ecarlier         ###   ########.fr       */
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
	sort_deque();

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
Group the elements of X into [n/2] pairs of elements -> if oddm leave the last element unpair
Put the larger one of the pair on the front
recursively sort the [n/2] larger elements from each pair
*/

/* ----------------------- vector ----------------------- */

void PmergeMe::sort_vector()
{
	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>::iterator			it;



	for (it = this->_vec.begin(); it != this->_vec.end() && it + 1 != this->_vec.end() ; it += 2)
	{
		if (it + 1 != this->_vec.end())
		{
			std::pair<int, int>	p(*it, *(it + 1));
			pairs.push_back(p);
		}
	}
	if (it != this->_vec.end())
	{
		std::pair<int, int> p(-1, *it);
		pairs.push_back(p);
	}
	pairs = sortPairs(pairs);

	#ifdef MERGEINSERT
		std::cout << CYAN << BOLD << "### STARTING MERGE-INSERT SORT FOR VECTOR ###" << RESET << std::endl;
		std::cout << "Starting mergeInsertSort on vector with pairs : ";
		for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
		std::cout << "(" << it->first << ", " << it->second << ") ";
		}
		std::cout << std::endl;
	#endif
	pairs = mergeInsertSortVector(pairs);

	#ifdef DEBUG_MODE
		std::cout << "Vector pairs sorting complete." << RESET << std::endl;
		printPairs(pairs);
	#endif

}

std::vector<std::pair<int, int> > PmergeMe::mergeInsertVector(const std::vector<std::pair<int, int> >& left, const std::vector<std::pair<int, int> >& right)
{

	#ifdef MERGEINSERT
        std::cout << "Merging two vectors..." << std::endl;
        std::cout << "	 Left vector: ";
		printPairs(left);
        std::cout << "	 Right vector: ";
		printPairs(right);
        std::cout << std::endl;
    #endif

	std::vector<std::pair<int, int> > result;
	std::vector<std::pair<int, int> >::const_iterator itLeft = left.begin();
	std::vector<std::pair<int, int> >::const_iterator itRight = right.begin();

		while (itLeft != left.end() && itRight != right.end()) {
			if (itLeft->first <= itRight->first) {
				result.push_back(*itLeft);
				++itLeft;
			} else {
				result.push_back(*itRight);
				++itRight;
			}
		}

		while (itLeft != left.end()) {
			result.push_back(*itLeft);
			++itLeft;
		}

		while (itRight != right.end()) {
			result.push_back(*itRight);
			++itRight;
		}
		return result;
}

std::vector<std::pair<int, int> > PmergeMe::mergeInsertSortVector( const std::vector<std::pair<int, int> >& pairs)
{
	#ifdef MERGEINSERT
        std::cout << "Starting mergeInsertSort on vector with pairs : ";
		printPairs(pairs);
        std::cout << RESET << std::endl;
    #endif
	if (pairs.size() <= 1)
	{
		 #ifdef MERGEINSERT
            std::cout << "Base case reached with vector: ";
            for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
                std::cout << "(" << it->first << ", " << it->second << ") ";
            }
            std::cout << RESET << std::endl;
        #endif
		return pairs;
	}

	//divide in two parts
	std::vector<std::pair<int, int> >::const_iterator middle = pairs.begin() + pairs.size() / 2;
	std::vector<std::pair<int, int> > leftPart(pairs.begin(), middle);
	std::vector<std::pair<int, int> > rightPart(middle, pairs.end());

	#ifdef MERGEINSERT
		std::cout << "Divided vector into left and right halves." << std::endl;
		std::cout << "	 Left: ";
		printPairs(leftPart);
		std::cout << "	 Right: ";
		printPairs(rightPart);
		std::cout << RESET << std::endl;
	#endif

	//recursive sort
	leftPart = mergeInsertSortVector(leftPart);
	rightPart = mergeInsertSortVector(rightPart);

	//fusion
	return mergeInsertVector(leftPart, rightPart);
}

/* ----------------------- deque ----------------------- */

void PmergeMe::sort_deque()
{
	std::deque<std::pair<int, int> >	pairs;
	std::deque<int>::iterator			it;

	#ifdef DEBUG_MODE
		std::cout << YELLOW << "Sorting deque..." << std::endl;
	#endif

	for (it = this->_deq.begin(); it != this->_deq.end() && it + 1 != this->_deq.end() ; it += 2)
	{
		if (it + 1 != this->_deq.end())
		{
			std::pair<int, int>	p(*it, *(it + 1));
			pairs.push_back(p);
		}
	}

	if (it != this->_deq.end())
	{
		std::pair<int, int> p(-1, *it);
		pairs.push_back(p);
	}

	pairs = sortPairs(pairs);

	//recursiveVectorSort();

	#ifdef DEBUG_MODE
		std::cout << "Deque pairs sorting complete."<< RESET << std::endl;
		printPairs(pairs);

	#endif


}

















/* ----------------------- utilities  ----------------------- */

int PmergeMe::getMidPoint(int start, int end) {
	return(start + (end - start) / 2);
}



/* ----------------------- printing  ----------------------- */


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

/* ----------------------- getters ----------------------- */
double PmergeMe::getVectorSortingTime()
{
	return _vectorSortingTime;
}

double PmergeMe::getDequeSortingTime()
{
	return _dequeSortingTime;
}
