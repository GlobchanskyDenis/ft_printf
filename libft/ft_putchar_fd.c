/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:36:54 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/04 13:50:18 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	/*
	unsigned char	a;
	unsigned char	b;
	unsigned char	ch;

	if (!(c >> 7))
		write(fd, &c, 1);
	else
	{
		ch = (unsigned char)c;
		a = 0b11000000 | (ch >> 6);
		b = (ch & 0b00111111) | 0b10000000;
		write(fd, &a, 1);
		write(fd, &b, 1);
	} */
}
