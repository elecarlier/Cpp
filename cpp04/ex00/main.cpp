/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/05 21:41:08 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	return 0;
// }
int	main (void)
{
	{
		const Animal* meta = new Animal();
		//const WrongAnimal* wrongMeta = new WrongAnimal();
		const Animal* i = new Cat();
		const Animal* j = new Dog();
		//const WrongAnimal* k = new WrongCat();

		std::cout << std::endl;

		std::cout << meta->getType() << ": ";
		meta->makeSound();
		std::cout << i->getType() << ": ";
		i->makeSound();
		std::cout << j->getType() << ": ";
		j->makeSound();

		//std::cout << wrongMeta->getType() << ": ";
		//wrongMeta->makeSound();
		//std::cout << k->getType() << ": ";
		//k->makeSound();

		std::cout << std::endl;

		delete(meta);
		// delete(wrongMeta);
		delete(i);
		delete(j);
		// delete(k);
	}

	return (0);
}
