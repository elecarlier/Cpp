/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:21:19 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/26 16:37:50 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

/*
std::find(input_iterator first, input_iterator last, const T& value);
*/
void	replace(std::string &s1, std::string &s2, std::ifstream& inputFile, std::ofstream& outputFile)
{
	std::string line;
	size_t startPos;

	while (std::getline(inputFile, line))
	{
		startPos = 0;

		while ((startPos = line.find(s1, startPos)) != std::string::npos)
		{
			line = line.substr(0, startPos) + s2 + line.substr(startPos + s1.length());
			startPos += s2.length();
		}
		outputFile << line << std::endl;
	}

}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr
		<< "Error : Wrong number of arguments" << std::endl
		<< "<filename> <s1> <s2> expected" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string outputFilename = filename + ".replace";

	std::ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cerr << "Error : Unable to open file " << filename << std::endl;
		return (1);
	}

	std::ofstream outputFile(outputFilename);
	if (!outputFile.is_open()) {
		std::cerr << "Error : Unable to open file " << outputFilename << " pour l'écriture." << std::endl;
		return (1);
	}

	replace(s1, s2, inputFile, outputFile);

	inputFile.close();
	outputFile.close();

}


/*
step 2 : Open and Read the Original File: Check if the file can be opened. If not, print an error and exit.
step 3 :Create the New File: Create a new file with the name <filename>.replace.
step 4 :  Process the File Content: Read the content of the original file, replace every occurrence of s1 with s2, and write the modified content to the new file
*/
