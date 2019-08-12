/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:31:33 by forange-          #+#    #+#             */
/*   Updated: 2019/08/04 11:55:34 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dprintf(int fd, const char *restrict format, ...)
{
	t_printf	tprint;
	t_func		f_table[TYPE_NUM];
	char		*begin;

	ft_init_table(f_table);
	tprint.printed = 0;
	tprint.str = (char*)format;
	tprint.fd = fd;
	va_start(tprint.args, format);
	while ((begin = ft_strchr(tprint.str, '%')))
	{
		write(tprint.fd, tprint.str, begin - tprint.str);
		tprint.printed += begin - tprint.str;
		tprint.str = begin + 1;
		tprint.printed += parse_format(&tprint, f_table);
	}
	write(tprint.fd, tprint.str, ft_strlen(tprint.str));
	tprint.printed += ft_strlen(tprint.str);
	va_end(tprint.args);
	return (tprint.printed);
}

int				ft_printf(const char *restrict format, ...)
{
	t_printf	tprint;
	t_func		f_table[TYPE_NUM];
	char		*begin;

	ft_init_table(f_table);
	tprint.printed = 0;
	tprint.str = (char*)format;
	tprint.fd = 1;
	va_start(tprint.args, format);
	while ((begin = ft_strchr(tprint.str, '%')))
	{
		write(tprint.fd, tprint.str, begin - tprint.str);
		tprint.printed += begin - tprint.str;
		tprint.str = begin + 1;
		tprint.printed += parse_format(&tprint, f_table);
	}
	write(tprint.fd, tprint.str, ft_strlen(tprint.str));
	tprint.printed += ft_strlen(tprint.str);
	va_end(tprint.args);
	return (tprint.printed);
}
