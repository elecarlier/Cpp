/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:41 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/10 16:32:54 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		Cat(std::string const type);
		virtual ~Cat();

		virtual void	makeSound() const; //does not need to be virtual but good to remember they are special
};


#endif
