/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:11:41 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/09 18:18:09 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
		Cat();
		Cat(const Cat &copy);
		Cat(std::string const type);
		Cat &operator=(const Cat &copy);
		virtual ~Cat();

		virtual void	makeSound() const; //does not need to be virtual but good to remember they are special
};


#endif
