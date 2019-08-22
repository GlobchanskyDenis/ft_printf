/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:35:04 by forange-          #+#    #+#             */
/*   Updated: 2019/08/22 11:40:22 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*gen_help(t_printf *tprint, int len, unsigned long long in)
{
	char			*out;
	char			*temp;
	char			*prefix;

	prefix = NULL;
	temp = NULL;
	out = NULL;
	tprint->flag & F_PREC && len > tprint->prec ? tprint->flag &= ~F_ZERO : 0;
	if (tprint->flag & F_HASH && in && (prefix = ft_strdup("0x")))
		len += 2;
	if (tprint->flag & F_PREC && tprint->prec > (prefix ? len - 2 : len))
		temp = ft_strnewc(tprint->prec - (prefix ? len - 2 : len), '0');
	else if (tprint->flag & F_ZERO && tprint->width > len)
		temp = ft_strnewc(tprint->width - len, '0');
	if (prefix && temp)
		out = ft_strjoin(prefix, temp);
	if (out)
	{
		free(prefix);
		free(temp);
		return (out);
	}
	return (prefix ? prefix : temp);
}

static int			ft_gen_hex(unsigned long long in, t_printf *tprint)
{
	char			*filler;
	char			*prefix;
	char			*out;
	int				len;

	(!in && tprint->flag & F_PREC && !tprint->prec) ? filler = ft_strdup("") : \
		(filler = ft_ulltoa_base(in, 16));
	prefix = gen_help(tprint, ft_strlen(filler), in);
	out = ft_strjoin(prefix ? prefix : "", filler);
	ft_strdel(&prefix);
	ft_strdel(&filler);
	(tprint->flag & F_UP) ? ft_strupr(out) : 1;
	if ((len = ft_strlen(out)) >= tprint->width)
		write(tprint->fd, out, len);
	else
	{
		filler = ft_strnewc(tprint->width, ' ');
		(tprint->flag & F_MINUS) ? (ft_memcpy(filler, out, len)) : \
			ft_strcpy(filler + tprint->width - len, out);
		write(tprint->fd, filler, tprint->width);
		ft_strdel(&filler);
	}
	ft_strdel(&out);
	return (len > tprint->width ? len : tprint->width);
}

int					ft_hex_type(t_printf *tprint)
{
	unsigned long long	out;

	tprint->str++;
	tprint->flag & F_PREC && tprint->flag & F_ZERO ? \
		tprint->flag &= ~F_ZERO : 0;
	if (tprint->flag & L_HH)
		out = (unsigned char)va_arg(tprint->args, int);
	else if (tprint->flag & L_H)
		out = (unsigned short)va_arg(tprint->args, int);
	else if (tprint->flag & L_L)
		out = va_arg(tprint->args, unsigned long);
	else if (tprint->flag & L_LL)
		out = va_arg(tprint->args, unsigned long long);
	else
		out = va_arg(tprint->args, unsigned int);
	return (ft_gen_hex(out, tprint));
}

int					ft_bhex_type(t_printf *tprint)
{
	tprint->flag |= F_UP;
	return (ft_hex_type(tprint));
}
