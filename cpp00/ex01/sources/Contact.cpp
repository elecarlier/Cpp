/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:13:50 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/19 19:05:57 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MyAwesomePhonebook.hpp"

Contact::Contact()
{
	//std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact desconstructor called" << std::endl;
}

/* Seters */

void	Contact::setFirstName(const std::string &fname)
{
	this->_firstName = fname;
}

void	Contact::setLastName(const std::string &Lname)
{
	this->_lastName = Lname;
}

void	Contact::setNickname(const std::string &Nname)
{
	this->_nickName = Nname;
}

void	Contact::setDarkestSecret(const std::string &Dsecret)
{
	this->_darkestSecret = Dsecret;
}

void	Contact::setNumber(const std::string &number)
{
	this->_phoneNumber = number;
}

/* Getters */

std::string Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string Contact::getLastName() const
{
	return (this->_lastName);
}

std::string Contact::getNickname() const
{
	return (this->_nickName);
}

std::string Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}

std::string	Contact::getNumber() const
{
	return (this->_phoneNumber);
}
