/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:53:06 by ecarlier          #+#    #+#             */
/*   Updated: 2024/11/28 15:33:04 by ecarlier         ###   ########.fr       */
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

		bool isValidDate(const std::string& date);
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
};

std::ostream &operator<<(std::ostream &o, BitcoinExchange const &i);

#endif // BitcoinExchange_HPP
