/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:23:18 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 17:40:33 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "includes/ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	//Class is not instantiable
	// ScalarConverter test;

	if (argc != 2)
		std::cout << "Usage: ./conversion [str]" << std::endl;
	else
		ScalarConverter::convert(argv[1]);

	return 0;
}




/*
./convert 3.14
char: Non displayable
int: 3
float: 3.14f
double: 3.14

./convert 'A'
char: 'A'
int: 65
float: 65.0f
double: 65.0

./convert 100
char: 'd'
int: 100
float: 100.0f
double: 100.0

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

*/
