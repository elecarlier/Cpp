/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:42:42 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/18 19:36:57 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyAwesomePhonebook.hpp"

PhoneBook::PhoneBook()
{
	//std::cout << "PhoneBook constructor called" << std::endl;
	this->index = 0;
	this->full = 0;
}

PhoneBook::~PhoneBook()
{
	//std::cout << "PhoneBook desconstructor called" << std::endl;
}

void	PhoneBook::display(void)
{
	std::cout
	<< std::setw(10) << std::right << "index" << '|'
	<< std::setw(10) << std::right << "first name" << "|"
	<< std::setw(10) << std::right << "last name" << "|"
	<< std::setw(10) << std::right << "nickname" << "" << std::endl
	<< std::setw(44) << std::setfill('-') << "" << std::setfill(' ') << "\n";

	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].getFirstName().empty())
			break;
		std::cout << std::setw(10) << std::right << i + 1 << '|'
		<< std::setw(10) << truncate_str(this->contacts[i].getFirstName()) << '|'
		<< std::setw(10) << truncate_str(this->contacts[i].getLastName()) << '|'
		<< std::setw(10) << truncate_str(this->contacts[i].getNickname()) << '\n';
		i++;
	}
}
/*
Save a new contact
*/
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

	if (index == 8)
		full = 1;
	std::cout << "\033[35m" << "Contact successfully added.." <<  "\033[0m" << std::endl;
}

/*
display a specific contact
◦ Display the saved contacts as a list of 4 columns: index, first name, last
name and nickname.
◦ Each column must be 10 characters wide. A pipe character (’|’) separates
them. The text must be right-aligned. If the text is longer than the column,
it must be truncated and the last displayable character must be replaced by a
dot (’.’).
◦ Then, prompt the user again for the index of the entry to display. If the index
is out of range or wrong, define a relevant behavior. Otherwise, display the
contact information, one field per line
 */
void	PhoneBook::search()
{
	if (this->full == 0 && this->index == 0)
	{
		std::cout << "Phonebook is empty. Please add contacts." << std::endl;
		return;
	}
	display();
}

void	PhoneBook::exit()
{

}
/* EXIT
◦ The program quits and the contacts are lost forever */


