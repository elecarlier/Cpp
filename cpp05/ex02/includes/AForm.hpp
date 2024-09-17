/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:39:44 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/17 13:00:37 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP


#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const 	_name;
		bool				_signed;
		int const			_S_grade;
		int const			_E_grade;

	public:
		AForm();
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();

		void	beSigned(Bureaucrat bureaucrat);

		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw ();

		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw ();
		};

		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw ();
		};

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw ();
		};

		bool			getSigned() const;
		int				getSGrade() const;
		int				getEGrade() const;
		std::string		getName() const;


};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif
