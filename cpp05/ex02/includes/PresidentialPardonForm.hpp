/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:59:21 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/17 19:54:06 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public AForm
{
	private:
			std::string	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);

		void execute(Bureaucrat const & executor) const;

		std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);

#endif // PresidentialPardonForm_HPP
