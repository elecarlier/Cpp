/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:35:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/19 19:06:19 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "MyAwesomePhonebook.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		bool	_full;
		int		_index;
		int		_count;

	public:
		PhoneBook(); //constructor, automatically called when an object of a class is created
		~PhoneBook();

		void	add_contact(void);
		void	search(void);
		void	display(void);
};


#endif
