

# COLORS FOR PRINTING
GREEN = \033[0;32m
RESET = \033[0m

# DIRECTORIES
OBJ_DIR = obj
SRC_DIR = sources
INCL_DIR = includes

# EXECUTABLE NAME
NAME = ex00

# SOURCE FILES
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp

# OBJECT FILES
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# COMPILER
CC = c++

# COMPILATION FLAGS
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCL_DIR)

# COMMANDS
RM = rm -f
MKDIR = mkdir -p

# RULES

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR)/main.o: main.cpp
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking the executable..."
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

fclean: clean
	@echo "Cleaning all temporary files..."
	@$(RM) $(NAME)

clean:
	@echo "Cleaning object files and executable..."
	@$(RM) -r $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
