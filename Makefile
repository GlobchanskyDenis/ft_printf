# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 17:19:13 by bsabre-c          #+#    #+#              #
#    Updated: 2019/08/12 11:45:04 by bsabre-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	out
FLAGS	=	-Wall -Wextra -Werror

SRC		=	main.c					errors.c			long_math_1.c		\
			long_math_2.c			long_math_sum.c		long_math_sum2.c	\
			dl_list.c				long_math_mult.c	long_math_sqr.c		\
			ft_printf.c				type_chr.c			parser.c			\
			type_str.c				table.c				type_handlers.c		\
			type_hex.c				type_oct.c			type_float.c		\
			bonus.c

INCLUDE	=	ft_printf.h

# libraries
L_FT	=	./libft/
L_FT_A 	=	$(L_FT)libft.a

$(NAME) :
	make -C $(L_FT)
	gcc $(FLAGS) $(SRC) -I$(INCLUDE) $(L_FT_A) -o $(NAME)

clean :
	make clean -C $(L_FT)
	rm -rf .DS_Store
	rm -rf $(L_FT).DS_Store

fclean : clean
	make fclean -C $(L_FT)
	rm -f $(NAME)

all : $(NAME)

re: fclean $(NAME)
