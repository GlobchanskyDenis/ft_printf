/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:30:33 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/16 11:41:56 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_align_left(t_printf *tprint, char *out, int len)
{
	int			space;

	if (!tprint || !out)
		error_func_free(EMPTY_PTR, NULL, NULL, out);
	space = tprint->width - len;
	tprint->printed += tprint->width;
	if (tprint->flag & F_SPACE && *out != '-' && *out != '+' && space--)
		write(1, " ", 1);
	write(1, out, len);
	while (space--)
		write(1, " ", 1);
}

static void	print_align_right(t_printf *tprint, char *out, int len)
{
	int			space;

	if (!tprint || !out)
		error_func_free(EMPTY_PTR, NULL, NULL, out);
	space = tprint->width - len;
	tprint->printed += tprint->width;
	if (tprint->flag & F_ZERO)
	{
		if (tprint->flag & F_SPACE && *out != '-' && *out != '+' && space--)
			write(1, " ", 1);
		if (*out == '-' || *out == '+')
			write(1, out++, 1);
		while (space--)
			write(1, "0", 1);
		write(1, out, len);
	}
	else
	{
		while (space--)
			write(1, " ", 1);
		write(1, out, len);
	}
}

int			ft_float_type(t_printf *tprint)
{
	char		*out;
	int			len;
	long double	ld;

	if (!tprint)
		error_func_free(EMPTY_PTR, NULL, NULL, NULL);
	tprint->str++;
	(tprint->flag & L_BIGL) ? (ld = va_arg(tprint->args, long double)) : \
			(ld = (long double)va_arg(tprint->args, double));
	if (!(out = turn_flpoint_to_str(ld, tprint->base, tprint)))
		error_func_free(EMPTY_PTR, NULL, NULL, out);
	if (tprint->width <= (len = ft_strlen(out)))
	{
		if (tprint->flag & F_SPACE && *out != '-' && *out != '+' && \
				++(tprint->printed))
			write(1, " ", 1);
		write(1, out, len);
		tprint->printed += len;
	}
	else
		(tprint->flag & F_MINUS) ? (print_align_left(tprint, out, len)) : \
			(print_align_right(tprint, out, len));
	ft_strdel(&out);
	return (0);
}
