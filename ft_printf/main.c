/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:38:46 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/07/13 18:41:38 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			main(int argc, char *argv[])
{
	int		value;

	value = 29;
	if (argc == 1)
		argv = NULL;
	ft_printf("Hi, my name is %s, i'm %d years old.\
 I'm study at school #%d, and %% <- that is my favourite symbol", "Denis", value, 21);
	return (0);
}
