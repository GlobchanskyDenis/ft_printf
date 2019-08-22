/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:45:11 by kirill            #+#    #+#             */
/*   Updated: 2019/08/22 11:23:29 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_gen_ptr(void *ptr, t_printf *tprint)
{
	int		len;
	char	*filler;
	char	*out;

	filler = ft_ulltoa_base((unsigned long long)ptr, 16);
	len = ft_strlen(filler) + 2;
	out = ft_strjoin("0x", filler);
	ft_strdel(&filler);
	if (len >= tprint->width)
		write(tprint->fd, out, len);
	else
	{
		filler = ft_strnew(tprint->width);
		filler = (char*)ft_memset(filler, ' ', tprint->width);
		if (tprint->flag & F_MINUS)
			ft_strncpy(filler, out, len);
		else
			ft_strncpy(filler + tprint->width - len, out, len);
		write(tprint->fd, filler, tprint->width);
		ft_memdel((void**)&filler);
	}
	ft_strdel(&out);
	return (len > tprint->width ? len : tprint->width);
}

int			ft_ptr_type(t_printf *tprint)
{
	void	*var;

	tprint->str++;
	var = va_arg(tprint->args, void*);
	return (ft_gen_ptr(var, tprint));
}
