/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:18:21 by ecarlier          #+#    #+#             */
/*   Updated: 2024/12/03 16:15:38 by ecarlier         ###   ########.fr       */
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

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"


class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		double _vectorSortingTime;
		double _dequeSortingTime;

	public:
		PmergeMe(const std::vector<int> &vector, const std::deque<int> &deque);
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();


		void printVector(bool is_before);

		void printDeque(bool is_before);

		void sort_vector();
		void sort_deque();

		template <typename Container>
		Container sortPairs(Container pairs);

		std::vector<std::pair<int, int>> PmergeMe::sortPairs(std::vector<std::pair<int, int>> pairs);

		double getVectorSortingTime();
		double getDequeSortingTime();

		class CustomException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &i);
int getMidPoint(int start, int end);

#endif // PmergeMe_HPP
