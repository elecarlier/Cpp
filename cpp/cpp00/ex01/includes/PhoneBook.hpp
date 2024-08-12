/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:35:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/12 20:44:26 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		PhoneBook(); //constructor, automaticallu called when an object of a class is created
		~PhoneBook();


};


#endif
