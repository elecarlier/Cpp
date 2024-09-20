/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:35:17 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/20 12:19:49 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern {
	private:

	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

	AForm*	makeForm(std::string name, std::string target);
	AForm* makeSrubbery(std::string &target);
	AForm* makeRobotomy(std::string &target);
	AForm* makePresidential(std::string &target);

	class CreateFile : public std::exception
	{
		public:
			virtual const char* what() const throw ();

	};
};

std::string stringToupper(std::string str);

#endif // Intern_HPP
