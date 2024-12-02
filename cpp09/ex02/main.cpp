/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:21:32 by ecarlier          #+#    #+#             */
/*   Updated: 2024/12/02 18:24:57 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

int	main(int argc, char* argv[])
{

	if (argc < 2) {
		std::cout << "Error" << std::endl;
		return (0);
	}
	else
	{
        try
		{
			std::vector<int> vector;
			std::deque<int> deque;


			for (int i = 1; i < argc; ++i)
			{
				std::stringstream ss(argv[i]);
				int nbr;


				if (!(ss >> nbr) || !(ss.eof()))
					throw std::invalid_argument("Invalid number");

				if (nbr < 0)
					throw std::out_of_range("Negative number");
				vector.push_back(nbr);
				deque.push_back(nbr);
			}
			std::cerr << "Vector size before passing to PmergeMe: " << vector.size() << std::endl;
			std::cerr << "Deque size before passing to PmergeMe: " << deque.size() << std::endl;


			std::cerr << "Debug Mode: Before creating PmergeMe object" << std::endl;

			PmergeMe Pme(vector, deque);

		}

        catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			return (EXIT_FAILURE);
        }
    }
	return 0;

}
