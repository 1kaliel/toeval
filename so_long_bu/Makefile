# Executable name
NAME    = so_long

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Source files
SRC     = $(SRC_DIR)/main.c $(SRC_DIR)/map.c $(SRC_DIR)/render.c \
          $(SRC_DIR)/movement.c $(SRC_DIR)/utils.c $(SRC_DIR)/parse.c $(SRC_DIR)/kill.c

# Object files
OBJ     = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libraries
LIBFT_DIR = include/libft
PRINTF_DIR = include/ft_printf
GNL_DIR = include/get_next_line

LIBFT   = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
GNL_OBJ = $(GNL_DIR)/get_next_line.o $(GNL_DIR)/get_next_line_utils.o

# MiniLibX flags
MLX     = -lmlx -lXext -lX11 -lm

# Colors and Emojis
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
BLUE = \033[1;34m
RESET = \033[0m
SUCCESS = ✅
COMPILING = 🚀
CLEANING = 🧹

# Main rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF_LIB) $(GNL_OBJ)
	@echo "$(COMPILING) $(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(LIBFT) $(PRINTF_LIB) $(MLX) -o $(NAME)
	@echo "$(SUCCESS) $(GREEN)Build complete!$(RESET)"

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(COMPILING) $(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Compile libft
$(LIBFT):
	@echo "$(COMPILING) $(BLUE)Building libft...$(RESET)"
	@make -s -C $(LIBFT_DIR)

# Compile ft_printf
$(PRINTF_LIB):
	@echo "$(COMPILING) $(BLUE)Building ft_printf...$(RESET)"
	@make -s -C $(PRINTF_DIR)

# Compile get_next_line
$(GNL_OBJ):
	@echo "$(COMPILING) $(BLUE)Compiling get_next_line files...$(RESET)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $(GNL_DIR)/get_next_line.c -o $(GNL_DIR)/get_next_line.o
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $(GNL_DIR)/get_next_line_utils.c -o $(GNL_DIR)/get_next_line_utils.o

# Clean rules
clean:
	@echo "$(CLEANING) $(YELLOW)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@rm -f $(GNL_DIR)/*.o
	@make -s clean -C $(LIBFT_DIR)
	@make -s clean -C $(PRINTF_DIR)
	@echo "$(SUCCESS) $(GREEN)Object files cleaned.$(RESET)"

fclean: clean
	@echo "$(CLEANING) $(YELLOW)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_DIR)
	@make -s fclean -C $(PRINTF_DIR)
	@echo "$(SUCCESS) $(GREEN)Removed $(NAME).$(RESET)"

re: fclean all

.PHONY: all clean fclean re
