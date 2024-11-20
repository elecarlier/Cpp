GREEN = \033[0;32m
RESET = \033[0m

NAME = ex02

DEBUG = 0

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

ifeq ($(DEBUG),1)
	CFLAGS += -DDEBUG_MODE
endif

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
OBJ_DIR = obj

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking the executable..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

$(OBJ_DIR)/main.o: main.cpp
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

sources/%.o: sources/%.cpp includes/%.hpp
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp includes/%.hpp
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
