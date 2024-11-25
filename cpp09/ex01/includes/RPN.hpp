#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>


class RPN {
	private:
		std::stack<int> _numbers;

	public:
		RPN();
		RPN(const std::string& RPNExpression);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();

		void calculate_RNP(const std::string& RPNExpression);
		void validate_input(const std::string& RPNExpression);
		bool	isoperand( const char& c );
		void calc_op(const char& c);

		class InvalidRPNExpression : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class zeroDivison : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class unexpectedError : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

#endif // RPN_HPP
