/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/06 17:07:27 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongCat.hpp"
#include "includes/WrongAnimal.hpp"


int	main (void)
{
	{
		const Animal* meta = new Animal();
		const Animal* i = new Cat();
		const Animal* j = new Dog();

		std::cout << std::endl;
		std::cout << meta->getType() << ": ";
		meta->makeSound();
		std::cout << i->getType() << ": ";
		i->makeSound();
		std::cout << j->getType() << ": ";
		j->makeSound();


		std::cout << std::endl;

		delete(meta);
		delete(i);
		delete(j);
	}
	{
		std::cout << std::endl;
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* k = new WrongCat();

		std::cout << std::endl;
		std::cout << wrongMeta->getType() << ": ";
		wrongMeta->makeSound();
		std::cout << k->getType() << ": ";
		k->makeSound();
		std::cout << std::endl;

		delete(wrongMeta);
		delete(k);
	}

	return (0);
}
