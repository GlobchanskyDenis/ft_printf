/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 11:55:09 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/09 14:41:55 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_dl_lst	*dl_lstnew(char nbr, int rank, char base, t_dl_lst *prev_lst)
{
	t_dl_lst	*dst;

	if (!(dst = (t_dl_lst *)malloc(sizeof(t_dl_lst))))
		error_func_free(MALLOC_ERR, &dst, &prev_lst, NULL);
	dst->nbr = nbr;
	dst->rank = rank;
	dst->base = base;
	dst->prev = prev_lst;
	dst->next = NULL;
	return (dst);
}

void		dl_lst_insert(t_dl_lst *prev_lst, t_dl_lst *new_lst,
		t_dl_lst *next_lst)
{
	if (!prev_lst || !new_lst || !next_lst)
	{
		if (prev_lst)
			dl_lstdel(prev_lst);
		error_func_free(EMPTY_PTR, &new_lst, &next_lst, NULL);
	}
	prev_lst->next = new_lst;
	new_lst->prev = prev_lst;
	new_lst->next = next_lst;
	next_lst->prev = new_lst;
}

void		dl_lstdel(t_dl_lst *lst)
{
	t_dl_lst	*temp;

	while (lst->prev)
		lst = lst->prev;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

t_dl_lst	*dl_lstdel_if_zero(t_dl_lst *lst)
{
	t_dl_lst	*prev;
	t_dl_lst	*next;

	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	while (lst->prev)
	{
		prev = lst->prev;
		if (lst->nbr == 0)
		{
			next = lst->next;
			if (prev)
				prev->next = next;
			if (next)
				next->prev = prev;
			free(lst);
		}
		lst = prev;
	}
	return (lst);
}
