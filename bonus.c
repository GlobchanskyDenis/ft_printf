/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:37:40 by forange-          #+#    #+#             */
/*   Updated: 2019/08/11 13:00:44 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_base(t_printf *t_print)
{
	int	base;

	t_print->base = 10;
	if (*t_print->str == '_' && ft_isdigit(*(++t_print->str)))
	{
		base = ft_atoi(t_print->str);
		if (base && !(base % 2) && base <= 34)
		{
			t_print->base = base;
			while (ft_isdigit(*t_print->str))
				t_print->str++;
		}
	}
}
