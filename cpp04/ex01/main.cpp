/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/10 14:21:36 by ecarlier         ###   ########.fr       */
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
		const Animal* scooby = new Dog();
		const Animal* bagheera = new Cat();
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* k = new WrongCat();

		std::cout << std::endl;

		std::cout << scooby->getType() << " ";
		scooby->makeSound();
		std::cout << bagheera->getType() << " ";
		bagheera->makeSound();
		std::cout << meta->getType() << " ";
		meta->makeSound();
		std::cout << std::endl;

		std::cout << wrongMeta->getType() << ": ";
		wrongMeta->makeSound();
		std::cout << k->getType() << ": ";
		k->makeSound();
		std::cout << std::endl;

		delete(meta);
		delete(scooby);
		delete(bagheera);
		delete(wrongMeta);
		delete(k);
	}
	{
		std::cout << std::endl;
		std::cout << "\033[1;0mCreating an array of animals\033[0m" << std::endl;
		Animal*	array[4];
		for (int i = 0; i < 2; i++)
			array[i] = new Cat();
		for (int i = 2; i < 4; i++)
			array[i] = new Dog();

		std::cout << std::endl;
		std::cout << "\033[1;0mChecking the array\033[0m" << std::endl;
		for (size_t i = 0; i < 4; i++)
		{
			array[i]->getType();
			array[i]->makeSound();
		}

		/* Checking deep copies -> we need to ensure that the brain member object is copied, not just the pointer
		-> a new brain object must be created and not the just the pointer */
		std::cout << std::endl;
		std::cout << "\033[1;0mChecking that copies are deep copies\033[0m" << std::endl;

		Dog	basic;
		{
			Dog	tmp = basic;
		}

		std::cout << std::endl << "\033[1;0mProperly deleting\033[0m" << std::endl;
		for (size_t i = 0; i < 4; i++) {
			delete array[i];
			std::cout << std::endl;
		}

	}

	return (0);
}
