/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:18:21 by ecarlier          #+#    #+#             */
/*   Updated: 2024/12/02 16:35:30 by ecarlier         ###   ########.fr       */
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


class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		double _vectorSortingTime;
		double _dequeSortingTime;

	public:
		PmergeMe(std::vector<int> vector, std::deque<int> deque);
		//PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();


		void printVector(bool is_before);

		void printDeque(bool is_before);

		double getVectorSortingTime();
		double getDequeSortingTime();

		class CustomException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &i);

#endif // PmergeMe_HPP
