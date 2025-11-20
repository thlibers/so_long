# Nom du programme
NAME = so_long

# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes -I./mylibft -I./minilibx

# Chemins
SRC_DIR = srcs
OBJ_DIR = objs
LIBFT_DIR = mylibft
MLX_DIR = minilibx-linux

# Bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Flags de liaison
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Fichiers sources
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/parsing/map_parser.c \
       $(SRC_DIR)/parsing/map_validation.c \
       $(SRC_DIR)/parsing/path_checker.c \
       $(SRC_DIR)/graphics/init_window.c \
       $(SRC_DIR)/graphics/render.c \
       $(SRC_DIR)/game/movement.c \
       $(SRC_DIR)/game/events.c \
       $(SRC_DIR)/game/game_logic.c \

# Fichiers objets
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Couleurs pour l'affichage
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

# Règle par défaut
all: $(NAME)

# Compilation du programme principal
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation de la libft
$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft compiled!$(RESET)"

# Compilation de la MiniLibX
$(MLX):
	@echo "$(BLUE)Compiling MiniLibX...$(RESET)"
	@make -C $(MLX_DIR)
	@echo "$(GREEN)✓ MiniLibX compiled!$(RESET)"

# Nettoyage des fichiers objets
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# Nettoyage complet
fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✓ Full clean completed!$(RESET)"

# Recompilation complète
re: fclean all

# Test avec une carte valide
test: $(NAME)
	@echo "$(BLUE)Running test...$(RESET)"
	@./$(NAME) maps/valid_map.ber

# Vérification des fuites mémoire
valgrind: $(NAME)
	@echo "$(BLUE)Checking for memory leaks with valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) maps/valid_map.ber

# Règles .PHONY
.PHONY: all clean fclean re test leaks valgrind