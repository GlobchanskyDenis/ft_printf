/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:35:35 by forange-          #+#    #+#             */
/*   Updated: 2019/08/22 19:29:17 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_printf *tprint)
{
	char	*flag;
	char	*haystack;

	haystack = ft_strdup("-+ 0#");
	tprint->flag = 0;
	while (*tprint->str && (flag = ft_strchr(haystack, *tprint->str)) > 0)
	{
		tprint->flag |= (1 << (flag - haystack));
		tprint->str++;
	}
	tprint->flag & F_ZERO && tprint->flag & F_MINUS ? \
		tprint->flag &= ~F_ZERO : 0;
	tprint->flag & F_PLUS && tprint->flag & F_SPACE ? \
		tprint->flag &= ~F_SPACE : 0;
	ft_memdel((void**)&haystack);
}

static void	parse_width(t_printf *tprint)
{
	tprint->width = 0;
	if (ft_isdigit(*tprint->str))
	{
		tprint->width = ft_atoi(tprint->str);
		while (ft_isdigit(*tprint->str))
			tprint->str++;
	}
	else if (*tprint->str == '*')
	{
		tprint->width = va_arg(tprint->args, int);
		tprint->str++;
	}
	if (tprint->width < 0)
	{
		tprint->flag & F_ZERO ? tprint->flag &= ~F_ZERO : 0;
		tprint->flag |= F_MINUS;
	}
	tprint->width = ft_absi(tprint->width);
	if (tprint->width < 0)
		tprint->width = 0;
	return ;
}

static void	parse_prec(t_printf *tprint)
{
	tprint->prec = 0;
	if (*tprint->str != '.')
		return ;
	else
	{
		tprint->flag |= F_PREC;
		tprint->str++;
		if (ft_isdigit(*tprint->str))
		{
			tprint->prec = ft_atoi(tprint->str);
			while (ft_isdigit(*tprint->str))
				tprint->str++;
		}
		else if (*tprint->str == '*')
		{
			tprint->prec = va_arg(tprint->args, int);
			tprint->str++;
		}
		if (tprint->prec < 0)
			tprint->flag &= ~F_PREC;
	}
	return ;
}

static void	parse_lenght(t_printf *tprint)
{
	if (*tprint->str == 'h')
	{
		if (*(tprint->str + 1) == 'h')
			tprint->flag |= L_HH;
		else
			tprint->flag |= L_H;
	}
	else if (*tprint->str == 'l')
	{
		if (*(tprint->str + 1) == 'l')
			tprint->flag |= L_LL;
		else
			tprint->flag |= L_L;
	}
	else if (*tprint->str == 'L')
		tprint->flag |= L_BIGL;
	if (tprint->flag & (L_L | L_H | L_BIGL | L_LL | L_HH))
		tprint->str += (tprint->flag & (L_L | L_H | L_BIGL)) ? 1 : 2;
}

int			parse_format(t_printf *tprint, t_func f_table[])
{
	int		i;

	i = 0;
	parse_flags(tprint);
	parse_width(tprint);
	parse_prec(tprint);
	parse_lenght(tprint);
	parse_base(tprint);
	while (i < TYPE_NUM && tprint->printed >= 0)
	{
		if (*tprint->str == f_table[i].ch)
			return ((tprint->printed += f_table[i].func(tprint)));
		i++;
	}
	return (tprint->printed < 0 ? -1 : 0);
}
