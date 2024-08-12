/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:13:50 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/12 16:37:40 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact::Contact(){}

Contact::~Contact(){}


void	Contact::setFirstName(const std::string &fname)
{
	firstName = fname;
}

void	Contact::setLastName(const std::string &Lname)
{
	lastName = Lname;
}
void	Contact::setAge(int newAge)
{
	age = newAge;
}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}



