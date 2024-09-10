/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:42 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/10 16:32:54 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"


class Dog : public AAnimal
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
