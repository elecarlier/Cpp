/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:37:08 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 19:14:10 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/utils.hpp"

Base * generate(void)
{
	long	seed = 42;
	std::srand((std::time(&seed)));

	int random = rand() % 3;
	switch (random)
	{
		case 0:
			std::cout << "Type A generated" << std::endl;
			return new A();
		case 1:
			std::cout << "Type B generated" << std::endl;
			return new B();
		case 2:
			std::cout << "Type C generated" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

/*
When casting pointers:
if the cast is successful -> dynamic_cast returns a pointer to the target type
if the cast fails -> it returns nullptr
*/
void identify(Base* p)
{
	if (dynamic_cast<A*>(p) && dynamic_cast<A*>(p) != NULL)
		std::cout << "Type A pointer" << std::endl;
	else if (dynamic_cast<B*>(p) && dynamic_cast<B*>(p) != NULL)
		std::cout << "Type B pointer" << std::endl;
	else if (dynamic_cast<C*>(p) && dynamic_cast<C*>(p) != NULL)
		std::cout << "Type C pointer" << std::endl;
	else
		std::cout << "Unknown pointer type..." << std::endl;
}


/*
When casting references:
if the cast is successful -> dynamic_cast returns a reference to the target type
if the cast fails -> it throws a std::bad_cast exception.
*/
// void identify(Base& p)
// {
// 	try
// 	{
// 		(void)dynamic_cast<A&>(p);
// 		std::cout << "Type A reference" << std::endl;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		try
// 		{
// 			(void)dynamic_cast<B&>(p);
// 			std::cout << "Type B reference" << std::endl;
// 		}
// 		catch (const std::exception& e)
// 		{
// 			try
// 			{
// 				(void)dynamic_cast<C&>(p);
// 				std::cout << "Type C reference" << std::endl;
// 			}
// 			catch (const std::exception& e)
// 			{
// 				std::cout << "Unknown reference type..." << std::endl;
// 			}
// 		}
// 	}
// }
void identify(Base &p)
{
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Type A reference" << std::endl;
		return;
	}
	catch (std::exception& e) { }

	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Type B reference" << std::endl;
		return;
	}
	catch (std::exception& e) { }

	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "Type C reference" << std::endl;
		return;
	}
	catch (std::exception& e) { }

	std::cout << "Unknown reference type..." << std::endl;
}
