#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>

class RPN {
	private:
		
	public:
		RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();

		class CustomException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, RPN const &i);

#endif // RPN_HPP
