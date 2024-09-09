/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:42 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/09 18:29:56 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(const Dog &copy);
		Dog(std::string const type);
		Dog &operator=(const Dog &copy);
		virtual ~Dog();

		virtual void	makeSound() const;
};


#endif
