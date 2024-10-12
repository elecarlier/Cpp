/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:23:18 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 19:53:33 by ecarlier         ###   ########.fr       */
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
./ex00  3.14
char: Non displayable
int: 3
float: 3.14f
double: 3.14

./ex00 'A'
char: 'A'
int: 65
float: 65.0f
double: 65.0

./ex00 100
char: 'd'
int: 100
float: 100.0f
double: 100.0

./ex00 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

./ex00 nan
char: impossible
int: impossible
float: nanf
double: nan

./ex00 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

*/

/*
static_cast
Used for compile-time casting where types are related or conversions are well-defined.
Performs no runtime checks—assumes the cast is valid based on the code’s context.
Useful for implicit conversions (e.g., int to float) or explicit type casting where types are compatible.
Generally faster than dynamic_cast due to lack of runtime checks.
*/
