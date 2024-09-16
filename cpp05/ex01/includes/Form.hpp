/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:39:44 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/16 19:45:16 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP


#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const 	_name;
		bool				_signed;
		int const			_S_grade;
		int const			_E_grade;



	public:
		Form();
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();


		void	beSigned(Bureaucrat bureaucrat);

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

		bool			getSigned() const;
		int				getSGrade() const;
		int				getEGrade() const;
		std::string		getName() const;


};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif
