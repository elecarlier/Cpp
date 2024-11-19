/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:12:11 by ecarlier          #+#    #+#             */
/*   Updated: 2024/11/19 19:51:48 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
#define Span_HPP

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <climits>
#include <algorithm>


class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_vec;

	public:

		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		void	checkElement();


		class Spanfull : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NoElement : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class OnlyOneElement : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NoSpanFound : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Span const &i);

#endif // Span_HPP
