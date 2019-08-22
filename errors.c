/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:10:20 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/22 11:15:22 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	error_func_free(char *message, t_dl_lst **l1, t_dl_lst **l2, char *str)
{
	if (l1)
	{
		if (*l1)
			dl_lstdel(*l1);
	}
	if (l2)
	{
		if (*l2)
			dl_lstdel(*l2);
	}
	if (str)
		ft_strdel(&str);
	write(1, message, ft_strlen(message));
	exit(1);
}

void	error_func_free_lst(char *message, t_dl_lst **lst1, t_dl_lst **lst2,
		t_dl_lst **lst3)
{
	if (lst1)
	{
		if (*lst1)
			dl_lstdel(*lst1);
	}
	if (lst2)
	{
		if (*lst2)
			dl_lstdel(*lst2);
	}
	if (lst3)
	{
		if (*lst3)
			dl_lstdel(*lst3);
	}
	write(1, message, ft_strlen(message));
	exit(1);
}

void	*error_return_null_free(t_dl_lst **lst1, t_dl_lst **lst2,
		t_dl_lst **lst3, char *str)
{
	if (lst1)
	{
		if (*lst1)
			dl_lstdel(*lst1);
	}
	if (lst2)
	{
		if (*lst2)
			dl_lstdel(*lst2);
	}
	if (lst3)
	{
		if (*lst3)
			dl_lstdel(*lst3);
	}
	if (str)
		ft_strdel(&str);
	return (NULL);
}

char	*nan_inf(long double ld, t_printf *tprint)
{
	if (ld != ld)
	{
		tprint->flag &= ~(F_ZERO | F_SPACE);
		return (ft_strcpy(ft_strnew(3), tprint->flag & F_UP ? "NAN" : "nan"));
	}
	tprint->flag &= ~F_ZERO;
	if (ld < 0)
		return (ft_strcpy(ft_strnew(4), tprint->flag & F_UP ? "-INF" : "-inf"));
	if (tprint->flag & F_PLUS)
		return (ft_strcpy(ft_strnew(4), tprint->flag & F_UP ? "+INF" : "+inf"));
	return (ft_strcpy(ft_strnew(3), tprint->flag & F_UP ? "INF" : "inf"));
}
