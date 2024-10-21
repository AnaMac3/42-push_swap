CC= cc
CFLAGS= -Wall -Wextra -Werror

TARGET_DIR= ..
TARGET= $(TARGET_DIR)/checker 

LIB_FILE= libchecker.h
LIB_NAME= libchecker.a

LIBFT_DIR= ../my_libft
LIBFT_NAME= $(LIBFT_DIR)/libft.a

PS_DIR= ..
PS_LIB_NAME= $(PS_DIR)/libpush_swap.a

SRC_FILES= main.c \

OBJ_DIR= ./obj
OBJ_FILES= $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

all: $(TARGET)

$(LIB_NAME): $(OBJ_FILES)
	ar rcs $(LIB_NAME) $(OBJ_FILES)

$(TARGET): $(OBJ_FILES) $(LIB_NAME) $(LIBFT_NAME) $(PS_LIB_NAME)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES) -L $(PS_DIR) -lpush_swap -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: %.c $(LIB_FILE) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi

fclean: clean
	rm -f $(TARGET) $(LIB_NAME)

re: fclean all
