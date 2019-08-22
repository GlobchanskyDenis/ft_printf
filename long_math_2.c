/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math_create2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:33:58 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/22 11:21:45 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	kill_cur_node_go_next(t_dl_lst **lst)
{
	t_dl_lst	*tmp;

	if (!lst || !(*lst))
		error_func_free(EMPTY_PTR, NULL, NULL, NULL);
	if ((*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		(*lst)->prev = NULL;
	}
}

static void	get_char_from_dl_lst(char *dst, int *i, int *rank, t_dl_lst **lst)
{
	if (!lst || !(*lst) || !rank || !i || !dst)
		error_func_free(EMPTY_PTR, lst, NULL, dst);
	if (*rank == (*lst)->rank)
	{
		if ((*lst)->nbr < 10)
			dst[(*i)] = (*lst)->nbr + '0';
		else
			dst[(*i)] = (*lst)->nbr - 10 + 'A';
		kill_cur_node_go_next(lst);
		(*rank)--;
		(*i)++;
	}
	else if (*rank == 0)
	{
		dst[(*i)] = '.';
		(*rank)--;
		(*i)++;
	}
	else
	{
		dst[(*i)] = '0';
		(*rank)--;
		(*i)++;
	}
}

static void	add_sign_to_str(char *dst, int *i, t_sem sem, t_printf tprintf)
{
	if (sem.s)
	{
		dst[*i] = '-';
		(*i)++;
	}
	else if (tprintf.flag & F_PLUS)
	{
		dst[*i] = '+';
		(*i)++;
	}
}

char		*turn_dl_lst_to_str(t_dl_lst *lst, t_printf tprintf, t_sem sem)
{
	int			len;
	int			i;
	char		*dst;
	int			rank;

	if (!lst)
		error_func_free(EMPTY_PTR, NULL, NULL, NULL);
	round_up_dl_lst(&lst, (tprintf.flag & F_PREC) ? tprintf.prec : \
			STANDART_PRECISION);
	len = long_math_strlen(lst, &tprintf, sem);
	i = 0;
	while (lst->prev)
		lst = lst->prev;
	if (lst->rank > 0)
		rank = lst->rank;
	else
		rank = 1;
	if (!(dst = ft_strnew(len)))
		error_func_free(MALLOC_ERR, &lst, NULL, dst);
	add_sign_to_str(dst, &i, sem, tprintf);
	while (i < len)
		get_char_from_dl_lst(dst, &i, &rank, &lst);
	dl_lstdel(lst);
	return (dst);
}
