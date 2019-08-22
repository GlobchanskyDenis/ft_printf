# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kirill <kirill@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 23:08:59 by kirill            #+#    #+#              #
#    Updated: 2019/08/22 11:17:44 by bsabre-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

BIN_DIR=bin

BIN_NAME=out

BIN=$(addprefix $(BIN_DIR)/,$(BIN_NAME))

CC=gcc

CFLAGS=-Wall -Wextra -Werror
ifdef dbg
	CFLAGS += -g
endif

LIBFT = libft

DIR_O = temporary

HEADER = -I./$(LIBFT)

SOURCES = 	bonus.c \
			dl_list.c \
			errors.c \
			ft_printf.c \
			long_math_1.c \
			long_math_2.c \
			long_math_mult.c \
			long_math_round_up.c \
			long_math_sqr.c \
			long_math_sum.c \
			long_math_sum2.c \
			parser.c \
			table.c \
			type_chr.c \
			type_float.c \
			type_hex.c \
			type_int.c \
			type_oct.c \
			type_ptr.c \
			type_str.c \
			type_uint.c

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

.PHONY: all clean fclean re build

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling libft and libftprintf"
	@make -sC $(LIBFT)
	@echo "Done"
	@cp -p $(LIBFT)/libft.a ./$(NAME)
	@ar r $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: %.c
	@mkdir -p temporary
	@$(CC) $(HEADER) $(CFLAGS) -o $@ -c $<

build: $(BIN)

$(BIN): $(NAME) main.c
	@echo "compiling binary with main.c to /bin/out"
	@mkdir -p bin
	@$(CC) $(CFLAGS) $(HEADER) main.c -L. -lftprintf -o $(BIN)

clean:
	@echo "Removing objects"
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -sC $(LIBFT)
	@echo "Done"

fclean: clean
	@echo "Removing library"
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT)
	@echo "Done"
	@echo "Removing binary"
	@rm -rf $(BIN_DIR)
	@rm -rf ./.DS_Store
	@rm -rf ./$(LIBFT)/.DS_Store
	@echo "Done"

re: fclean all
