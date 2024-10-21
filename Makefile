CC= cc
CFLAGS= -Wall -Wextra -Werror

TARGET= push_swap

PS_LIB_FILE= libpush_swap.h 
PS_LIB_NAME= libpush_swap.a

LIBFT_DIR= ./my_libft
LIBFT= $(LIBFT_DIR)/libft.h
LIBFT_NAME= $(LIBFT_DIR)/libft.a

SRC_FILES= rules_swap.c rules_push.c rules_rotate.c rules_rev_rotate.c\
			args_manager.c stack_manager.c check_order.c\
			stack_utils.c stack_utils2.c other_utils.c\
			sort_small_stack.c \
			calculate_moves.c calculate_moves_utils.c \
			sort_long_stack.c \
			main.c \

OBJ_DIR= ./obj
OBJ_FILES= $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

BONUS_DIR= ./bonus

all: $(TARGET)

$(PS_LIB_NAME): $(OBJ_FILES)
	ar rcs $(PS_LIB_NAME) $(OBJ_FILES)

$(TARGET): $(OBJ_FILES) $(PS_LIB_NAME) $(LIBFT_NAME)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES) -L. -lpush_swap -L$(LIBFT_DIR) -lft

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c $(PS_LIB_FILE) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

bonus: all
	@make -C $(BONUS_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(BONUS_DIR)

fclean: clean
	rm -f $(TARGET) $(PS_LIB_NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(BONUS_DIR)

re: fclean all

.PHONY: bonus
