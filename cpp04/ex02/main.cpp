/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:57 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/13 17:35:50 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/AAnimal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongCat.hpp"
#include "includes/WrongAnimal.hpp"


int	main( void )
{
	{

		std::cout << std::endl;
		std::cout << "\033[1;0mCreating an array of animals\033[0m" << std::endl;
		AAnimal*	array[4]; //cannot instantiate an AAnimal object directly but can store pointers to objetcs of derived classes
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


	// AAnimal *animal = new AAnimal();


	// {
	// 	std::cout << "\033[1;32mChecking that an A_Animal cannot be instanciated\033[0m" << std::endl;

	// 	AAnimal	test;
	// }

}
