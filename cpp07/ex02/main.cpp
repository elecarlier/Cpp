/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:10:17 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/18 16:17:50 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int main()
{
	std::cout << "\033[34m" << "\n### Test default constructor ###" << "\033[0m" << std::endl;
	Array<int> emptyArray;
	std::cout << "Size of emptyArray : " << emptyArray.size() << std::endl;

	std::cout << "\033[34m" << "\n### Test array size 5 ###" << "\033[0m" << std::endl;
	Array<int> intArray(5);
	std::cout << "Size of IntArray : " << intArray.size() << std::endl;
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;


	for (unsigned int i = 0; i < intArray.size(); ++i)
		intArray[i] = i * 10;

	std::cout << "\033[34m" << "\nmodifiying the array..." << "\033[0m" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

	std::cout << "\033[34m" << "\n### Test copy constructor ###" << "\033[0m" << std::endl;
	Array<int> copyArray(intArray);
	for (unsigned int i = 0; i < copyArray.size(); ++i)
		std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;

	std::cout << "\033[34m" << "\nmodifiying copyArray..." << "\033[0m" << std::endl;
	copyArray[0] = 100;
	std::cout << "\nafter modification of copyArray[0] :" << std::endl;
	std::cout << "copyArray[0] = " << copyArray[0] << std::endl;
	std::cout << "intArray[0] = " << intArray[0] << std::endl;


	std::cout << "\033[34m" << "\n### Test asignation operator ###" << "\033[0m" << std::endl;
	Array<int> assignArray;
	assignArray = intArray;
	for (unsigned int i = 0; i < assignArray.size(); ++i)
		std::cout << "assignArray[" << i << "] = " << assignArray[i] << std::endl;


	std::cout << "\033[34m" << "\n### Out of bounds test###" << "\033[0m" << std::endl;
	try
	{
		std::cout << intArray[10] << std::endl; // Devrait lever une exception
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught : " << e.what() << std::endl;
	}

    return 0;
}
