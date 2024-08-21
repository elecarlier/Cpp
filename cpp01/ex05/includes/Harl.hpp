/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:24:50 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/21 12:28:00 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>


class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:

		Harl();
		~Harl();
		void complain( std::string level );
};


#endif
