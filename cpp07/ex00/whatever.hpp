/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:49:27 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 21:55:09 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T &a, T &b)
{
	if (b <= a)
		return b;
	else
		return a;
}

template <typename T>
T max(T &a, T &b)
{
	if (b >= a)
		return b;
	else
		return a;
}

#endif
