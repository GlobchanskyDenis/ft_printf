/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:07:38 by forange-          #+#    #+#             */
/*   Updated: 2019/08/10 19:12:42 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_gen_oct(unsigned long long in, t_printf *tprint)
{
	char				*filler;
	char				*digit;
	int					len;

	digit = ft_strjoin(tprint->flag & F_HASH ? "0" : "", ft_ulltoa_base(in, 8));
	len = ft_strlen(digit);
	len = (tprint->flag & F_PREC && len < tprint->prec) ? tprint->prec : len;
	filler = ft_strnew(len > tprint->width ? len : tprint->width);

	ft_strdel(&digit);
	ft_strdel(&filler);
	return (len);
}

int						ft_oct_type(t_printf *tprint)
{
	unsigned long long	out;

	tprint->str++;
	tprint->flag & (F_PREC | F_ZERO) ? tprint->flag &= ~F_ZERO : 0;
	if (tprint->flag & F_PREC && !tprint->prec && !tprint->width)
		return (0);
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
	return (ft_gen_oct(out, tprint));
}
