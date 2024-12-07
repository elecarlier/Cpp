/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:18:21 by ecarlier          #+#    #+#             */
/*   Updated: 2024/12/07 15:09:26 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <time.h>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"


class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		std::vector<int>	_jacobsthalSequence;
		size_t				_size;

		double				_vectorSortingTime;
		double				_dequeSortingTime;

	public:
		PmergeMe(const std::vector<int> &vector, const std::deque<int> &deque);
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();


		void printVector(bool is_before);
		void printDeque(bool is_before);
		void printTime(int size);

		const std::vector<int> sort_vector();
		const std::deque<int> sort_deque();

		std::deque<std::pair<int, int> > mergeInsertDeque(const std::deque<std::pair<int, int> >& left, const std::deque<std::pair<int, int> >& right);
		std::deque<std::pair<int, int> > mergeInsertSortDeque( const std::deque<std::pair<int, int> >& pairs);

		std::vector<std::pair<int, int> > mergeInsertSortVector( const std::vector<std::pair<int, int> >& pairs);
		std::vector<std::pair<int, int> > mergeInsertVector(const std::vector<std::pair<int, int> >& left, const std::vector<std::pair<int, int> >& right);

		void	generateJacobstalSequence(int size);

		double getVectorSortingTime();
		double getDequeSortingTime();
		size_t getSize();


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

		template <typename Container>
		void printPairs(const Container& pairs)
		{
			typename Container::const_iterator it;
			// std::cout << "Pairs: ";
			for (it = pairs.begin(); it != pairs.end(); ++it)
			{
				std::cout << "(" << it->first << ", " << it->second << ") ";
			}
			std::cout << std::endl;
		}


		class CustomException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &i);
int getMidPoint(int start, int end);

#endif // PmergeMe_HPP
