/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:23:18 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 16:57:22 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "includes/ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	//Class is not instantiable
	//ScalarConverter test;

	if (argc != 2)
		std::cout << "Usage: ./conversion [str]" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
    // Test cases for each type
    // std::string testCases[] = {"a", "!", "42", "+42", "-100", "3.14f", "-2.71f", "3.14",
    //                            "+inf", "+inff", "-inf", "-inff", "nan", "nanf", "hello", "42abc"};

    // for (const std::string &test : testCases) {
    //     e_type result = ScalarConverter::getType(test);
    //     std::cout << "Input: " << test << " -> Type: " << result << std::endl;
    // }

    return 0;
}




