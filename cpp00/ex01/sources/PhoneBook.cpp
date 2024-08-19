/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:42:42 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/18 22:35:33 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyAwesomePhonebook.hpp"

PhoneBook::PhoneBook()
{
	//std::cout << "PhoneBook constructor called" << std::endl;
	this->index = 0;
	this->full = 0;
	this->count = 0;
}

PhoneBook::~PhoneBook()
{
	//std::cout << "PhoneBook desconstructor called" << std::endl;
}

void	PhoneBook::display(void)
{
	std::cout << "|" << std::setw(43) << std::setfill('~') << "|" << std::setfill(' ') << std::endl;
	std::cout << "|                PHONE  BOOK               |" << std::endl;
	std::cout << "|" << std::setw(43) << std::setfill('~') << "|" << std::setfill(' ') << std::endl << std::endl;
	std::cout
	<< std::setw(10) << std::right << "index" << '|'
	<< std::setw(10) << std::right << "first name" << "|"
	<< std::setw(10) << std::right << "last name" << "|"
	<< std::setw(10) << std::right << "nickname" << "" << std::endl
	<< std::setw(44) << std::setfill('-') << "" << std::setfill(' ') << "\n";

	for (int i = 0; i < 8; i++)
	{
		if (i >= this->count)
			break;
		std::cout << std::setw(10) << std::right << i + 1 << '|'
		<< std::setw(10) << truncate_str(this->contacts[i].getFirstName()) << '|'
		<< std::setw(10) << truncate_str(this->contacts[i].getLastName()) << '|'
		<< std::setw(10) << truncate_str(this->contacts[i].getNickname()) << '\n';
	}
}

void	PhoneBook::add_contact(void)
{
	std::cout << "\033[35m" << " -- Adding a new contact -- " << "\033[0m" << std::endl;
	if (full)
	{
		full = 0;
		index = 0;
	}
	if (std::cin.peek() == '\n') std::cin.ignore();
	this->contacts[index].setFirstName(get_input("First name : "));
	this->contacts[index].setLastName(get_input("Last name : "));
	this->contacts[index].setNickname(get_input("Nickname : "));
	this->contacts[index].setNumber(get_input("Phone number : "));
	this->contacts[index].setDarkestSecret(get_input("Darkest secret : "));
	index++;
	count++;
	if (index == 8)
		full = 1;
	std::cout << "\033[35m" << "Contact successfully added.." <<  "\033[0m" << std::endl;
}

void	PhoneBook::search()
{
	std::string	input;

	if (this->full == 0 && this->count == 0)
	{
		std::cout << "\033[31m" <<  "Phonebook is empty. Please add contacts." << "\033[0m" << std::endl;
		return;
	}
	display();
	std::cout << "\nEnter the index of the contact you would like to see : " << std::endl;
	if (std::cin.peek() == '\n') std::cin.ignore();
	while (1)
	{
		std::getline(std::cin, input);
		if (input.length() == 1)
		{
			int index_i = input[0] - 49;
			if (index_i >= 8 || index_i < 0 || index_i >= this->count)
			{
				std::cout << "\033[31m" << "Invalid index. Please enter a valid index.. " << "\033[0m" << std::endl;
				std::cout << "Enter the index of the contact you would like to see : " << std::endl;
			}
			else
			{
				std::cout << "First name : " << this->contacts[index_i].getFirstName() << std::endl;
				std::cout << "Last name : " << this->contacts[index_i].getLastName() << std::endl;
				std::cout << "Nick name : " << this->contacts[index_i].getNickname() << std::endl;
				std::cout << "Phone Number : " << this->contacts[index_i].getNumber() << std::endl;
				std::cout << "Darkest secret : " << this->contacts[index_i].getDarkestSecret() << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "\033[31m" << "Index out of range. Please enter a valid index.. " << "\033[0m" << std::endl;
			std::cout << "\033[1m" << "Enter the index of the contact you would like to see : " << "\033[0m" << std::endl;
		}
	}
}

