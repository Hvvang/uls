NAME = libmx.a

INC = libmx.h

INCI = inc/libmx.h

SRC = \
mx_calc_num.c \
mx_count_words.c \
mx_get_char_index.c \
mx_itoa.c \
mx_nbr_to_hex.c \
mx_printchar.c \
mx_printint.c \
mx_printstr.c \
mx_quicksort.c \
mx_str_reverse.c \
mx_strcmp.c \
mx_strcpy.c \
mx_strdel.c \
mx_strdup.c \
mx_strjoin_no_leaks.c \
mx_strjoin.c \
mx_strlen.c \
mx_strncmp.c \
mx_strncpy.c \
mx_strndup.c \
mx_strnew.c \
mx_strsplit.c \
mx_swap_char.c \

SRCS = $(addprefix src/, $(SRC))

OBJ = $(SRC:%.c=%.o)

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@cp $(SRCS) .
	@cp $(INCI) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@ar crs $(NAME) $(OBJ)
	@mkdir -p obj
	@mv $(OBJ) ./obj
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf $(SRC) $(INC)
	@rm -rf ./obj
reinstall: uninstall install
