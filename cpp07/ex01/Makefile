GREEN = \033[0;32m
RESET = \033[0m


OBJ_DIR = obj

NAME = ex01

SRCS =	main.cpp\

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f
MKDIR = mkdir -p

$(OBJ_DIR)/%.o: %.cpp
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

print-NAME:
	@echo $(NAME)

$(NAME) : $(addprefix $(OBJ_DIR)/, $(OBJS))
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

fclean : clean
	@$(RM) $(NAME)

clean :
	@$(RM) -r $(OBJ_DIR)

re : fclean all

.PHONY : all clean fclean re
