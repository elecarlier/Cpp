/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:59:17 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/18 15:31:54 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F function)
{
	for (size_t i = 0; i < length; ++i)
		function(array[i]);
}

template <typename T>
void printElement(T& element)
{
	std::cout << element << " ";
}
template <typename T>
void incrementElement(T& element)
{
	++element;
}

#endif
