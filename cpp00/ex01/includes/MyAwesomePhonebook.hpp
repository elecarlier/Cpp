/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhonebook.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:47:32 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/18 20:39:33 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYAWESOMEPHONEBOOK_HPP
#define MYAWESOMEPHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string	get_input(std::string prompt);
std::string truncate_str(std::string str);

#endif
