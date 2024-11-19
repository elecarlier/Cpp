/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:31:14 by ecarlier          #+#    #+#             */
/*   Updated: 2024/11/19 19:09:31 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/easyfind.hpp"
int main()
{
	try {

		std::cout << YELLOW << "TEST 0 : Vector" << RESET << std::endl;
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		std::cout << "Vector: Found " << *easyfind(vec, 3) << std::endl;

		std::cout << YELLOW << "TEST 1 : list" << RESET << std::endl;
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);
		std::cout << "List: Found " << *easyfind(lst, 20) << std::endl;


		std::cout << YELLOW << "TEST 2 : not found " << RESET << std::endl;
		std::cout << "Vector: Found " << *easyfind(vec, 6) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
