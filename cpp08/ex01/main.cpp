/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:31:14 by ecarlier          #+#    #+#             */
/*   Updated: 2024/11/19 21:20:26 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Span.hpp"

int main()
{

	{
		std::cout << YELLOW << "TEST 0 : subject test" << RESET << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	{
		std::cout << YELLOW << "TEST 1 : empty span" << RESET << std::endl;
		Span sp = Span(0); // Crée un Span vide (impossible d'ajouter des éléments)

		try {
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error (empty span): " << e.what() << std::endl;  // Doit lancer une exception de type "NoElement"
		}

		try {
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error (empty span): " << e.what() << std::endl;  // Devrait aussi lancer une exception
		}


	}
	{
		std::cout << YELLOW << "TEST 2 : one element" << RESET << std::endl;
		Span sp = Span(1); // Crée un Span qui peut contenir 1 seul élément
		sp.addNumber(5); // Ajoute un seul élément

		try {
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error (one element): " << e.what() << std::endl;  // Devrait lancer une exception "OnlyOneElement"
		}

		try {
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error (one element): " << e.what() << std::endl;  // Devrait aussi lancer une exception
		}


	}
	{
		std::cout << YELLOW << "TEST 3 : neg elements" << RESET << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(-3);
		sp.addNumber(17);
		sp.addNumber(-9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Devrait afficher 2 (9 - 11)
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;  // Devrait afficher 26 (17 - (-9))


	}
	{
		std::cout << YELLOW << "TEST 4 : adding too much element" << RESET << std::endl;
		Span sp = Span(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);

		try {
			sp.addNumber(4);
		} catch (const std::exception& e) {
			std::cerr << "Error (overflow): " << e.what() << std::endl;
		}


	}
	{
		std::cout << YELLOW << "TEST 5 : adding with range" << RESET << std::endl;
		Span sp(10);

		sp.addNumber(1);

		std::vector<int> nums = {10, 20, 30, 40};

		sp.addRange(nums.begin(), nums.end());
		std::cout << sp << std::endl;

	}
	{
		try {
			std::cout << YELLOW << "TEST 6 : overflow with range " << RESET << std::endl;
			Span sp(2);

			sp.addNumber(1);

			std::vector<int> nums = {10, 20, 30, 40};

			sp.addRange(nums.begin(), nums.end()); // Cette ligne lèvera une exception
			std::cout << sp << std::endl;

		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl; // Affichera le message d'erreur de l'exception
		}
	}
	// {
	// 	std::cout << YELLOW << "TEST 4 : big capacity" << RESET << std::endl;
	// 	Span sp = Span(10000);

	// 	for (int i = 0; i < 10000; ++i) {
	// 		sp.addNumber(i);
	// 	}

	// 	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	// 	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	// }
}


