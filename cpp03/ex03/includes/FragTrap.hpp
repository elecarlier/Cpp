/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:17:28 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/05 15:45:19 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: virtual public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap &operator=(const FragTrap &copy);

		void highFivesGuys(void);
};

#endif
