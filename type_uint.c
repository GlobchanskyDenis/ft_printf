/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:25:32 by forange-          #+#    #+#             */
/*   Updated: 2019/08/22 11:46:32 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*gen_help(t_printf *tprint, int len)
{
	char			*temp;

	temp = NULL;
	tprint->flag & F_PREC && len > tprint->prec ? tprint->flag &= ~F_ZERO : 0;
	if (tprint->flag & F_PREC && tprint->prec > len)
		temp = ft_strnewc(tprint->prec - len, '0');
	else if (tprint->flag & F_ZERO && tprint->width > len)
		temp = ft_strnewc(tprint->width - len, '0');
	return (temp);
}

static int	ft_gen_unsgn(unsigned long long in, t_printf *tprint)
{
	char	*filler;
	char	*out;
	char	*prefix;
	int		len;

	(!in && tprint->flag & F_PREC && !tprint->prec) ? filler = ft_strdup("") : \
		(filler = ft_ulltoa_base(in, 10));
	prefix = gen_help(tprint, ft_strlen(filler));
	out = ft_strjoin(prefix ? prefix : "", filler);
	ft_strdel(&prefix);
	ft_strdel(&filler);
	if ((len = ft_strlen(out)) >= tprint->width)
		write(tprint->fd, out, len);
	else
	{
		filler = ft_strnewc(tprint->width, ' ');
		(tprint->flag & F_MINUS) ? ft_memcpy(filler, out, len) : \
			ft_strcpy(filler + tprint->width - len, out);
		write(tprint->fd, filler, tprint->width);
		ft_strdel(&filler);
	}
	ft_strdel(&out);
	return (len > tprint->width ? len : tprint->width);
}

int			ft_unsgn_type(t_printf *tprint)
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
	return (ft_gen_unsgn(out, tprint));
}
