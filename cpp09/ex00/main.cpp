
#include <iostream>
#include "includes/BitcoinExchange.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "Error: could not open file in main" << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		BitcoinExchange btc(argv[1]);
	}
	catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
	}
	return 0;
}
