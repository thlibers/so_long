# Name
NAME = so_long

# Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes -I./mylibft -I./minilibx

# Paths
SRC_DIR = srcs
OBJ_DIR = objs
LIBFT_DIR = mylibft
MLX_DIR = minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Flags Mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Srcs
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/parsing/map_parser.c \
       $(SRC_DIR)/parsing/map_validation.c \
       $(SRC_DIR)/parsing/path_checker.c \
       $(SRC_DIR)/graphics/init_window.c \
       $(SRC_DIR)/graphics/render.c \
       $(SRC_DIR)/game/movement.c \
       $(SRC_DIR)/game/events.c

# Obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

# Compilation program
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

# Compilation files obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation mylibft
$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft compiled!$(RESET)"

# Compilation MiniLibX
$(MLX):
	@echo "$(BLUE)Compiling MiniLibX...$(RESET)"
	@make -C $(MLX_DIR)
	@echo "$(GREEN)✓ MiniLibX compiled!$(RESET)"

# Clean obj files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# Complete clean
fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✓ Full clean completed!$(RESET)"

# Complete recompilation
re: fclean all

# Valid map
test: $(NAME)
	@echo "$(BLUE)Running test...$(RESET)"
	@./$(NAME) maps/valid_map.ber

# Leaks
valgrind: $(NAME)
	@echo "$(BLUE)Checking for memory leaks with valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) maps/valid_map.ber

# Rule .PHONY
.PHONY: all clean fclean re test leaks valgrind