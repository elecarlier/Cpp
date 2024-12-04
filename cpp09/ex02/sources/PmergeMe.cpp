/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:20:11 by ecarlier          #+#    #+#             */
/*   Updated: 2024/12/04 16:59:14 by ecarlier         ###   ########.fr       */
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


	generateJacobstalSequence(_vec.size());

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

	#ifdef DEBUG_MODE
		std::cout << CYAN << "## Starting Vector sorting ###" << RESET << std::endl;
	#endif

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
		std::cout << CYAN << "Vector pairs sorting complete."  << std::endl;
		printPairs(pairs);
	#endif

	std::vector<int>	mainchain, pend;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		mainchain.push_back(it->first);
		pend.push_back(it->second);
	}
	if (!pend.empty())
		mainchain.insert(mainchain.begin(), pend[0]);

	#ifdef DEBUG_MODE
		std::cout << "Mainchain: ";
		for (std::vector<int>::iterator it = mainchain.begin(); it != mainchain.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Pend: ";
		for (std::vector<int>::iterator it = pend.begin(); it != pend.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
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

	while (itLeft != left.end() && itRight != right.end())
	{
		if (itLeft->first <= itRight->first)
		{
			result.push_back(*itLeft);
			++itLeft;
		}
		else
		{
			result.push_back(*itRight);
			++itRight;
		}
	}

	while (itLeft != left.end())
	{
		result.push_back(*itLeft);
		++itLeft;
	}

	while (itRight != right.end())
	{
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
		std::cout << YELLOW << "## Starting deque sorting ###" << RESET << std::endl;
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
	pairs = mergeInsertSortDeque(pairs);

	#ifdef DEBUG_MODE
		std::cout << YELLOW << "Deque pairs sorting complete." << std::endl;
		printPairs(pairs);
	#endif

}



std::deque<std::pair<int, int> > PmergeMe::mergeInsertSortDeque( const std::deque<std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return pairs;

	//divide in two parts
	std::deque<std::pair<int, int> >::const_iterator middle = pairs.begin() + pairs.size() / 2;
	std::deque<std::pair<int, int> > leftPart(pairs.begin(), middle);
	std::deque<std::pair<int, int> > rightPart(middle, pairs.end());

	//recursive sort
	leftPart = mergeInsertSortDeque(leftPart);
	rightPart = mergeInsertSortDeque(rightPart);

	//fusion
	return mergeInsertDeque(leftPart, rightPart);
}





std::deque<std::pair<int, int> > PmergeMe::mergeInsertDeque(const std::deque<std::pair<int, int> >& left, const std::deque<std::pair<int, int> >& right)
{

	std::deque<std::pair<int, int> > result;
	std::deque<std::pair<int, int> >::const_iterator itLeft = left.begin();
	std::deque<std::pair<int, int> >::const_iterator itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (itLeft->first <= itRight->first)
		{
			result.push_back(*itLeft);
			++itLeft;
		}
		else
		{
			result.push_back(*itRight);
			++itRight;
		}
	}

	while (itLeft != left.end())
	{
		result.push_back(*itLeft);
		++itLeft;
	}

	while (itRight != right.end())
	{
		result.push_back(*itRight);
		++itRight;
	}

	return result;
}







/* ----------------------- utilities  ----------------------- */

/*
Jacobstal  : 0,1,1,3,5,11,21...
then insert Jacob number first then the indexes before it

skip index 0
*/
void	PmergeMe::generateJacobstalSequence(int size)
{
	if (size % 2 == 0)
		size = size / 2;
	else
		size = (size / 2) + 1;


	this->_jacobsthalSequence.clear();
	int last = 1, before_last = 1, next = 0;
	_jacobsthalSequence.push_back(1);
	_jacobsthalSequence.push_back(1);

	while (last < size)
	{
		next = last + (2* before_last);
		if (next >= size)
			next = size;
		before_last = last;
		last = next;
		for (int i = next; i > before_last; i--)
			_jacobsthalSequence.push_back(i);
	}

	_jacobsthalSequence.erase(_jacobsthalSequence.begin());
	for (unsigned long i = 0; i < _jacobsthalSequence.size(); i++)
		_jacobsthalSequence[i] = _jacobsthalSequence[i] - 1;

	#ifdef DEBUG_MODE
		std::vector<int>::const_iterator it;
		for (it = _jacobsthalSequence.begin(); it != _jacobsthalSequence.end(); ++it)
			std::cout << RESET << *it << " ";
		std::cout << " _jacobsthalSequence" << std::endl;
	#endif



}

/* ----------------------- printing  ----------------------- */


void PmergeMe::printVector(bool is_before)
{
	if (is_before)
		std::cout << RESET << "Vector "  << "before:\t";
	else
		std::cout << RESET << "Vector "<< "after:\t";

	std::vector<int>::const_iterator it;
	for (it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printDeque(bool is_before)
{
	if (is_before)
		std::cout << RESET << "Deque " << " before:\t" ;
	else
		std::cout << RESET << "Deque "  << " after:\t";

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
