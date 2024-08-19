/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:26:53 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/19 19:04:47 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP


#include "MyAwesomePhonebook.hpp"

class Contact
{
	private:	//used only inside the class
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public: //can be used outside
		Contact(); //constructor, automatically called when an object of a class is created
		~Contact();

		// /* setters */
		void	setFirstName(const std::string &fname);
		void	setLastName(const std::string &Lname);
		void	setNickname(const std::string &Nname);
		void	setNumber(const std::string &number);
		void	setDarkestSecret(const std::string &Dsecret);

		// /* getters */
		//void		display_contact(int index);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string	getNickname() const;
		std::string	getDarkestSecret() const;
		std::string	getNumber() const;
};

#endif
