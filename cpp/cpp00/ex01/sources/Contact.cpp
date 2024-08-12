/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:13:50 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/12 20:48:48 by ecarlier         ###   ########.fr       */
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


void	Contact::setFirstName(const std::string &fname)
{
	this->firstName = fname;
}

void	Contact::setLastName(const std::string &Lname)
{
	this->lastName = Lname;
}
void	Contact::setAge(int newAge)
{
	if (newAge >= 0)
		this->age = newAge;
	else
		std::cerr << "Error: Age must be greater than 0." << std::endl;

}

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}


int Contact::getAge() const
{
	return (this->age);
}

