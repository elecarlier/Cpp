/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:26:53 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/12 18:47:03 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
	private:	//used only inside the class
		std::string	firstName;
		std::string	lastName;
		int			age;
	public: //can be used outside
		Contact(); //constructor, automatically called when an object of a class is created
		~Contact();

		// /* setters */
		void	setFirstName(const std::string &fname);
		void	setLastName(const std::string &Lname);
		void	setAge(int newAge);

		// /* getters */
		int	getAge() const;
		std::string getFirstName() const;
		std::string getLastName() const;
};

#endif
