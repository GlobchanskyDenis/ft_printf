/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:25:32 by forange-          #+#    #+#             */
/*   Updated: 2019/08/10 19:08:06 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_ptr_type(t_printf *tprint)
{
	uintptr_t	ptr;
	char		*out;

	ptr = va_arg(tprint->args, uintptr_t);
	out = ft_itoa((int)ptr);
	write(1, out, ft_strlen(out));
	return (0);
}

int			ft_int_type(t_printf *tprint)
{
	(void)tprint;
	return (0);
}

int			ft_unsgn_type(t_printf *tprint)
{
	(void)tprint;
	return (0);
}
