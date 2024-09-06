/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:41 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/06 17:30:54 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.cpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		virtual ~Cat();

		virtual void	makeSound() const; //does not need to be virtual but good to remember they are special
};


#endif
