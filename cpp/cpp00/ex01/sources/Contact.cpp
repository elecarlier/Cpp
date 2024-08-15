/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:13:50 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/15 13:48:04 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"


Contact::Contact()
{
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact desconstructor called" << std::endl;
}

/* Seters */

void	Contact::setFirstName(const std::string &fname)
{
	this->firstName = fname;
}

void	Contact::setLastName(const std::string &Lname)
{
	this->lastName = Lname;
}

void	Contact::setNickname(const std::string &Nname)
{
	this->nickName = Nname;
}

void	Contact::setDarkestSecret(const std::string &Dsecret)
{
	this->darkestSecret = Dsecret;
}

void	Contact::setNumber(const int &number)
{
	this->phoneNumber = number;
}

/* Getters */

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

std::string Contact::getNickname() const
{
	return (this->nickName);
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}

int	Contact::getNumber() const
{
	return (this->phoneNumber);
}
