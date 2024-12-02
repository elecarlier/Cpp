/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:20:11 by ecarlier          #+#    #+#             */
/*   Updated: 2024/12/02 16:37:48 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// PmergeMe::PmergeMe()
// {
// 	//std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
// }


PmergeMe::PmergeMe(std::vector<int> vector, std::deque<int> deque)
{
    std::cerr << "Debug Mode: Inside PmergeMe constructor" << std::endl;

    // Vérification de la taille des containers reçus
    std::cerr << "Debug Mode: Vector size = " << vector.size() << std::endl;
    std::cerr << "Debug Mode: Deque size = " << deque.size() << std::endl;

    _vec = vector;
    _deq = deque;

    // Vérification de l'état des containers
    std::cerr << "Debug Mode: After copying data to _vec and _deq" << std::endl;
    printVector(1);  // Assurez-vous que printVector accepte bien _vec et le bon argument
    printDeque(1);    // Assurez-vous que printDeque accepte bien _deq et le bon argument
}

PmergeMe::~PmergeMe()
{
	//std::cout << "\033[32m" << "Destructor called" << "\033[0m" << std::endl;
}

/*NOT DONE*/
PmergeMe::PmergeMe(const PmergeMe &copy)
{
    this->_vec = copy._vec;
    this->_deq = copy._deq;
}

/*NOT DONE*/
PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		this->_vec = copy._vec;
		this->_deq = copy._deq;
	}
	return *this;
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
	std::cout << std::endl << std::endl;
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
}

double PmergeMe::getVectorSortingTime()
{
	return _vectorSortingTime;
}

double PmergeMe::getDequeSortingTime()
{
	return _dequeSortingTime;
}
