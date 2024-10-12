/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:40:50 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 19:12:08 by ecarlier         ###   ########.fr       */
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
