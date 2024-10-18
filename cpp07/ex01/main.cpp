/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:02:37 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/18 15:41:16 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {


	std::cout << "\033[34m" << "### Test with integers ###" << "\033[0m" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Array before incrementElement() : ";
	iter(intArray, intArrayLength, printElement<int>);
	std::cout << "\n";

	iter(intArray, intArrayLength, incrementElement<int>);

	std::cout << "Array after incrementElement():   ";
	iter(intArray, intArrayLength, printElement<int>);
	std::cout << "\n";

	std::cout << "\033[34m" << "### Test with strings ###" << "\033[0m" << std::endl;
	std::string strArray[] = {"Hello", "World", "42" "Berlin"};
	size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);


	std::cout << "Array of strings: ";
	iter(strArray, strArrayLength, printElement<std::string>);
	std::cout << "\n";

	return 0;
}
