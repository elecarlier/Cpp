/*
1) Group the elements of X into [n/2] pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
2) Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.
3) Recursively sort the [n/2] larger elements from each pair, creating a sorted sequence S of [n/2] of the input elements, in ascending order, using the merge-insertion sort.
4) Insert at the start of S the element that was paired with the first and smallest element of S
5) Insert the remaining [n/2] - 1 elements of X∖S into S. one at a time, with a specially chosen insertion  Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.


Group the elements of X into [n/2] pairs of elements -> if oddm leave the last element unpair
Put the larger one of the pair on the front
recursively sort the [n/2] larger elements from each pair
*/
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
			double	vectorTime;
			double	dequeTime;
			std::vector<int> vector;
			clock_t start_v = clock();

			for (int i = 1; i < argc; ++i)
			{
				std::stringstream ss(argv[i]);
				int nbr;

				if (!(ss >> nbr) || !(ss.eof()))
					throw std::invalid_argument("Invalid number");

				if (nbr < 0)
					throw std::out_of_range("Negative number");
				vector.push_back(nbr);
			}
			clock_t end_v = clock();
			double vector_dataManagement = ((double)(end_v - start_v) / CLOCKS_PER_SEC) *1000000;


			clock_t start_d = clock();
			std::deque<int> deque;
			for (int i = 1; i < argc; ++i)
			{
				std::stringstream ss(argv[i]);
				int nbr;

				if (!(ss >> nbr) || !(ss.eof()))
					throw std::invalid_argument("Invalid number");

				if (nbr < 0)
					throw std::out_of_range("Negative number");
				deque.push_back(nbr);
			}
			clock_t end_d = clock();
			double deque_dataManagement = ((double)(end_d - start_d) / CLOCKS_PER_SEC) *1000000;

			PmergeMe Pme(vector, deque);

			vectorTime = Pme.getVectorSortingTime() + vector_dataManagement;
			dequeTime =  Pme.getDequeSortingTime() + deque_dataManagement;


			std::cout << "Time to process a range of " << Pme.getSize() << " elements with std::vector : " << vectorTime<< "us" << std::endl;
			std::cout << "Time to process a range of "<< Pme.getSize() << " elements with std::deque : " << dequeTime << "us" << std::endl;


		}

		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			return (EXIT_FAILURE);
		}
	}
	return 0;

}

