/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:53:06 by ecarlier          #+#    #+#             */
/*   Updated: 2024/12/02 14:16:01 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <limits>
#include <cctype>


#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"


class BitcoinExchange {
	private:
		std::map<std::string, double> _dataMap;
		std::map<std::string, double> _inputMap;

	public:
		BitcoinExchange(std::string date);
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		void calculateRes(double value, std::string date);
		bool isValidDate(const std::string& date);
		void readInputFile(std::string path);
		void parseInput(std::string path);
		void parseDatebase();
		void checkDate(std::string date);
		void checkValue(std::string value);

		class OpenFileException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class InvalidDate : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class InvalidValue : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class ValueNegativeException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class ValueTooBig : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, BitcoinExchange const &i);

#endif // BitcoinExchange_HPP
