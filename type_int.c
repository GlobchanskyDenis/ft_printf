/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:51:13 by kirill            #+#    #+#             */
/*   Updated: 2019/08/22 20:19:04 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_swap(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

static char	*gen_help(t_printf *tprint, int len, long long in)
{
	char			*temp;
	char			*pre;
	char			*out;

	temp = NULL;
	pre = NULL;
	out = NULL;
	tprint->flag & F_PREC && len > tprint->prec ? tprint->flag &= ~F_ZERO : 0;
	if ((tprint->flag & (F_PLUS | F_SPACE)) && (in >= 0) && \
		(pre = ft_strdup(tprint->flag & F_PLUS ? "+" : " ")))
		len += 1;
	if (tprint->flag & F_PREC && tprint->prec > (pre || in < 0 ? len - 1 : len))
		temp = ft_strnewc(tprint->prec - (pre || in < 0 ? len - 1 : len), '0');
	else if (tprint->flag & F_ZERO && tprint->width > len)
		temp = ft_strnewc(tprint->width - len, '0');
	(pre && temp) ? (out = ft_strjoin(pre, temp)) : "1";
	if (out)
	{
		free(pre);
		free(temp);
		return (out);
	}
	return (pre ? pre : temp);
}

static int	ft_gen_int(long long in, t_printf *tprint)
{
	char	*filler;
	char	*out;
	char	*prefix;
	int		len;

	(!in && tprint->flag & F_PREC && !tprint->prec) ? filler = ft_strdup("") : \
		(filler = ft_lltoa_base(in, tprint->base));
	prefix = gen_help(tprint, ft_strlen(filler), in);
	out = ft_strjoin(prefix ? prefix : "", filler);
	ft_strdel(&prefix);
	ft_strdel(&filler);
	ft_swap(&out[0], (prefix = ft_strchr(out, '-')) ? prefix : &out[0]);
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

int			ft_int_type(t_printf *tprint)
{
	long long	out;

	tprint->str++;
	tprint->flag & F_PREC && tprint->flag & F_ZERO ? \
		tprint->flag &= ~F_ZERO : 0;
	if (tprint->flag & L_HH)
		out = (char)va_arg(tprint->args, int);
	else if (tprint->flag & L_H)
		out = (short)va_arg(tprint->args, int);
	else if (tprint->flag & L_L)
		out = va_arg(tprint->args, long);
	else if (tprint->flag & L_LL)
		out = va_arg(tprint->args, long long);
	else
		out = va_arg(tprint->args, int);
	return (ft_gen_int(out, tprint));
}
