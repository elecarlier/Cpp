NAME = phonebook

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_DIR	=	./sources/
HEAD_DIR	=	./includes/
OBJ_DIR		=	${SRCS_DIR}.o

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking the executable..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files and executable..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning all temporary files..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
