# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 17:19:13 by bsabre-c          #+#    #+#              #
#    Updated: 2019/07/12 17:49:45 by bsabre-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= out
FLAGS		= -Wall -Wextra -Werror

# directories
SRC_DIR		= ./ft_printf/
L_FT		= ./libft/

SRC			= $(SRC_DIR)main.c $(SRC_DIR)ft_printf.c
INCLUDE		= $(SRC_DIR)ft_printf.h

# libraries
L_FT_A 		= $(L_FT)libft.a

$(NAME) :
	make -C $(L_FT)
	gcc $(FLAGS) $(SRC) -I$(INCLUDE) $(L_FT_A) -o $(NAME)

clean :
	make clean -C $(L_FT)
	rm -rf .DS_Store
	rm -rf $(SRC_DIR).DS_Store
	rm -rf $(L_FT).DS_Store

fclean : clean
	make fclean -C $(L_FT)
	rm -f $(NAME)

all : $(NAME)

re: fclean $(NAME)
