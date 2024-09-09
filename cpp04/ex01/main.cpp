/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/09 19:04:32 by ecarlier         ###   ########.fr       */
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
		// const Cat* garfield = new Cat();
		// const Dog* marty = new Dog();

		std::cout << std::endl;

		std::cout << scooby->getType() << " ";
		scooby->makeSound();
		std::cout << bagheera->getType() << " ";
		bagheera->makeSound(); //will output the cat sound!
		std::cout << meta->getType() << " ";
		meta->makeSound();
		std::cout << std::endl;

		std::cout << wrongMeta->getType() << ": ";
		wrongMeta->makeSound();
		std::cout << k->getType() << ": ";
		k->makeSound();
		std::cout << std::endl;

	}
	{

	}

	return (0);
}
