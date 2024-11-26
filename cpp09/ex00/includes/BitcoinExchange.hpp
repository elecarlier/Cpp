/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:53:06 by ecarlier          #+#    #+#             */
/*   Updated: 2024/11/26 15:13:07 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> _dataMap;

	public:
		BitcoinExchange(std::string date);
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		void parseInput(std::string path);
		void parseDatebase();
		void checkDate(std::string date);
		void checkValue(std::string value);

		class OpenFileException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		// class OpenFileException : public std::exception {
		// 	public:
		// 		virtual const char* what() const throw();
		// };
};

std::ostream &operator<<(std::ostream &o, BitcoinExchange const &i);

#endif // BitcoinExchange_HPP
