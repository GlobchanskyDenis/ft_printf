/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:20:25 by forange-          #+#    #+#             */
/*   Updated: 2019/08/22 00:30:15 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_func	ft_add_table(char type, int (*func)(t_printf *tprint))
{
	t_func		out;

	out.ch = type;
	out.func = func;
	return (out);
}

void			ft_init_table(t_func *table)
{
	table[0] = ft_add_table('s', ft_str_type);
	table[1] = ft_add_table('c', ft_char_type);
	table[2] = ft_add_table('p', ft_ptr_type);
	table[3] = ft_add_table('d', ft_int_type);
	table[4] = ft_add_table('i', ft_int_type);
	table[5] = ft_add_table('o', ft_oct_type);
	table[6] = ft_add_table('u', ft_unsgn_type);
	table[7] = ft_add_table('x', ft_hex_type);
	table[8] = ft_add_table('X', ft_bhex_type);
	table[9] = ft_add_table('f', ft_float_type);
	table[10] = ft_add_table('%', ft_char_type);
	table[11] = ft_add_table('F', ft_bfloat_type);
}
