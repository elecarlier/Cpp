/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:53:06 by ecarlier          #+#    #+#             */
/*   Updated: 2024/12/07 14:32:26 by ecarlier         ###   ########.fr       */
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
#include <iomanip>

#include <string>    // Pour std::string, std::stoi, etc.
#include <sstream>   // Pour std::stringstream, std::istringstream
#include <cctype>    // Pour isdigit()
#include <iostream>

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

	public:
		BitcoinExchange(std::string date);
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		void calculateRes(double value, std::string date);
		bool isValidDate(const std::string& date);
		void readInputFile(std::string path);
		void parseDatebase();
		void writeDatabaseToTempFile();

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
		class emptyLine : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

bool isNotSpace(unsigned char c);

#endif // BitcoinExchange_HPP
