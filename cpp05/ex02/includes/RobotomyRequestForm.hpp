/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:59:20 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/17 17:26:38 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);

		void execute(Bureaucrat const & executor) const;
		
		std::string getTarget() const;

		// class CustomException : public std::exception {
		// public:
		// 	virtual const char* what() const throw();
		// };
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);

#endif // RobotomyRequestForm_HPP
