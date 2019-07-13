/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:37:25 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/07/13 18:38:51 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_list	*ft_return_int_specifier(va_list argptr)
{
	t_list	*dst;

	dst = ft_lstnew_fag(ft_itoa(va_arg(argptr, int)), (size_t)0);
	return (dst);
}

static t_list	*ft_return_str_specifier(va_list argptr)
{
	t_list	*dst;

	dst = ft_lstnew_fag(va_arg(argptr, char *), (size_t)0);
	return (dst);
}

static t_list	*ft_return_char_specifier(va_list argptr)
{
	t_list	*dst;
	char	*str;

	str = ft_strnew(10);
	str = va_arg(argptr, char *);
	str[1] = '\0';
	dst = ft_lstnew_fag(str, (size_t)0);
	return (dst);
}

static t_list	*ft_addstr_to_list(const char *restrict format, size_t i,
		size_t begin)
{
	t_list		*dst;
	char		*str;

	if (i - begin <= 0)
		return (NULL);
	dst = ft_lstnew_fag(NULL, (size_t)0);
	str = (char *)malloc(sizeof(char) * (i - begin + 1));
	dst->content = str;
	str[i - begin] = '\0';
	str = ft_strncpy(str, &(format[begin]), i - begin);
	return (dst);
}

static t_list	*ft_return_dash_specifier(void)
{
	t_list		*dst;
	char		*str;

	dst = ft_lstnew_fag(NULL, (size_t)0);
	str = ft_strnew(1);
	str[0] = '%';
	dst->content = str;
	return (dst);
}

static t_list	*ft_add_specifier_to_lst(const char *restrict format,
		va_list argptr, t_list **lst, size_t *i)
{
	*lst = *lst;
	if (format[*i + 1] == 'd')
	{
		(*i) += 2;
		return(ft_return_int_specifier(argptr));
	}
	else if (format[*i + 1] == 's')
	{
		(*i) += 2;
		return(ft_return_str_specifier(argptr));
	}
	else if (format[*i + 1] == '%')
	{
		(*i) += 2;
		return(ft_return_dash_specifier());
	}
	else if (format[*i + 1] == 'c')
	{
		(*i) += 2;
		return(ft_return_char_specifier(argptr));
	}
	(*i)++;
	return (NULL);
}

static t_list	*ft_parser(const char *restrict format, va_list argptr)
{
	size_t	i;
	size_t	begin;
	t_list	*head;
	t_list	*lst;

	i = 0;
	begin = 0;
	head = ft_lstnew_fag(NULL, (size_t)0);
	lst = head;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			i++;
		if ((lst->next = ft_addstr_to_list(format, i, begin)))
			lst = lst->next;
		if (format[i])
		{
			if ((lst->next = ft_add_specifier_to_lst(format, argptr, &lst, &i)))
				lst = lst->next;
		}
		begin = i;
	}
	return (head);
}

void			ft_printf(const char *restrict format, ...)
{
	va_list	argptr;
	t_list	*head;

	va_start(argptr, format);
	head = ft_parser(format, argptr);
	while (head)
	{
		//ft_putstr("str : ");
		ft_putstr(head->content);
		//ft_putchar('\n');
		head = head->next;
	}
	va_end(argptr);
}
