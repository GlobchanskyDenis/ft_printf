/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 14:28:14 by forange-          #+#    #+#             */
/*   Updated: 2019/08/04 14:28:35 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putwchar_fd(wchar_t c, int fd)
{
	if (c < 0x80)
	   	ft_putchar_fd (c, fd);
	else if (c < 0x800)
	{
		ft_putchar_fd ((0xC0 | (c>>6)), fd);
		ft_putchar_fd (0x80 | (c & 0x3F), fd);
		return (2);
	}
	else if (c < 0x10000)
	{
		ft_putchar_fd (0xE0 | (c>>12), fd);
		ft_putchar_fd (0x80 | ((c>>6) & 0x3F), fd);
		ft_putchar_fd (0x80 | (c & 0x3F), fd);
		return (3);
	}
	else if (c < 0x200000)
	{
		ft_putchar_fd (0xF0 | (c>>18), fd);
		ft_putchar_fd (0x80 | ((c>>12) & 0x3F), fd);
		ft_putchar_fd (0x80 | ((c>>6) & 0x3F), fd);
		ft_putchar_fd (0x80 | (c & 0x3F), fd);
		return (4);
	}
	return (1);
}
