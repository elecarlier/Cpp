/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:40 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/10 16:24:56 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <string>
#include <iostream>

/* A for abstract */
class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &copy);
		virtual ~AAnimal();

		virtual void	setType(std::string type);
		std::string		getType() const;

		virtual void	makeSound() const = 0;

};

#endif

