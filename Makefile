# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kirill <kirill@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 23:08:59 by kirill            #+#    #+#              #
#    Updated: 2019/08/12 21:09:28 by kirill           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

BIN_DIR=bin

BIN_NAME=out

BIN=$(addprefix $(BIN_DIR)/,$(BIN_NAME))

CC=gcc

CFLAGS=-Wall -Wextra -Werror

LIBFT = libft

DIR_O = temporary

HEADER = -I./$(LIBFT)

SOURCES = 	bonus.c				\
			dl_list.c			\
			errors.c			\
			ft_printf.c			\
			long_math_1.c		\
			long_math_2.c		\
			long_math_mult.c	\
			long_math_sqr.c		\
			long_math_sum.c		\
			long_math_sum2.c	\
			parser.c			\
			table.c				\
			type_chr.c			\
			type_float.c		\
			type_handlers.c		\
			type_hex.c			\
			type_oct.c			\
			type_str.c

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
	@$(CC) $(HEADER) $(FLAGS) -o $@ -c $<

build: $(BIN)

$(BIN): $(NAME) main.c
	@echo "compiling binary with main.c to /bin/out"
	@mkdir -p bin
	@$(CC) $(FLAGS) main.c -L. -lftprintf -o $(BIN)

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
	@echo "Done"

re: fclean all
