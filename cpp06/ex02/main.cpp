/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:40:50 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 19:52:54 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Base.hpp"
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"
#include "includes/utils.hpp"

int main() {
	Base *super = generate();
	std::cout << "Identified using pointer:\t";
	identify(super);
	std::cout << "Identified using reference:\t";
	identify(&(*super));
	delete super;
}

/*
dynamic_cast
Used for safely casting pointers or references in polymorphic class hierarchies.
Checks if the cast is valid at runtime, returning nullptr for pointers or throwing std::bad_cast for references if the cast fails.
Requires at least one virtual function in the base class, typically a virtual destructor.
Slower than other casts due to runtime type checking.
*/
