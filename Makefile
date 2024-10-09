CC= cc
CFLAGS=-Wall -Wextra -Werror

TARGET= push_swap

SRC_FILES= rules_swap.c rules_push.c rules_rotate.c \
			rules_rev_rotate.c stack_manager.c

OBJ_FILES= $(SRC_FILES:.c=.o)

PS_LIB_FILE= libpush_swap.h 
PS_LIB_NAME= libpush_swap.a

LIBFT_DIR = ./my_libft
LIBFT = $(LIBFT_DIR)/libft.h
LIBFT_NAME = ./my_libft/libft.a

all: $(LIBFT_NAME) $(PS_LIB_NAME) $(TARGET)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(PS_LIB_NAME): $(OBJ_FILES)
	ar rcs $(PS_LIB_NAME) $(OBJ_FILES)

$(TARGET): $(OBJ_FILES) $(LIBFT_NAME) $(PS_LIB_NAME)
	$(CC) $(CFLAGS) -o $(TARGET) -L. -lpush_swap -L$(LIBFT_DIR) -lft

%.o: %.c $(PS_LIB_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(TARGET) $(PS_LIB_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
