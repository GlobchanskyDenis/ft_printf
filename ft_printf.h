/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:32:31 by forange-          #+#    #+#             */
/*   Updated: 2019/08/22 00:30:35 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

# define STANDART_PRECISION 6
# define TYPE_NUM	12
# define F_MINUS	(1 << 0)
# define F_PLUS		(1 << 1)
# define F_SPACE	(1 << 2)
# define F_ZERO		(1 << 3)
# define F_HASH		(1 << 4)
# define L_HH		(1 << 5)
# define L_H		(1 << 6)
# define L_L		(1 << 7)
# define L_LL		(1 << 8)
# define L_BIGL		(1 << 9)
# define F_PREC		(1 << 10)
# define F_UP		(1 << 11)

# define EMPTY_PTR	"NULL pointer found! Set breakpoints!\n"
# define MALLOC_ERR	"malloc error! Set braakpoints!\n"
# define WRONG_VAL	"the value is wrong! Set breakpoints!\n"

typedef struct	s_printf
{
	int				printed;
	unsigned short	flag;
	int				width;
	int				prec;
	int				fd;
	va_list			args;
	char			*str;
	int				base;
}				t_printf;

typedef struct	s_dl_lst
{
	char			nbr;
	int				rank;
	char			base;
	struct s_dl_lst	*next;
	struct s_dl_lst	*prev;
}				t_dl_lst;

typedef struct	s_sem
{
	size_t			s;
	size_t			e;
	size_t			m;
	char			base;
}				t_sem;

typedef int		(*t_handler)(t_printf *tprint);

typedef struct	s_func
{
	t_handler		func;
	char			ch;
}				t_func;

int				ft_printf(const char *restrict format, ...);
int				ft_dprintf(int fd, const char *restrict format, ...);

void			print_arg(char *str, t_printf *tprint);
int				parse_format(t_printf *tprint, t_func f_table[]);
void			parse_base(t_printf *t_print);

int				ft_str_type(t_printf *tprint);
int				ft_char_type(t_printf *tprint);
int				ft_ptr_type(t_printf *tprint);
int				ft_int_type(t_printf *tprint);
int				ft_oct_type(t_printf *tprint);
int				ft_unsgn_type(t_printf *tprint);
int				ft_hex_type(t_printf *tprint);
int				ft_bhex_type(t_printf *tprint);
int				ft_float_type(t_printf *tprint);
int				ft_bfloat_type(t_printf *tprint);

void			ft_init_table(t_func *table);

t_dl_lst		*dl_lstnew(char nbr, int rank, char base,
		t_dl_lst *prev);
void			dl_lstdel(t_dl_lst *lst);
t_dl_lst		*dl_lstdel_if_zero(t_dl_lst *lst);
void			dl_lst_insert(t_dl_lst *prev_lst, t_dl_lst *new_lst,
		t_dl_lst *next_lst);

void			error_func_free(char *message, t_dl_lst **l1,
		t_dl_lst **l2, char *str);
void			error_func_free_lst(char *message, t_dl_lst **lst1,
		t_dl_lst **lst2, t_dl_lst **lst3);
void			*error_return_null_free(t_dl_lst **lst1,
		t_dl_lst **lst2, t_dl_lst **lst3, char *str);
char			*nan_inf(long double ld, t_printf *tprint);

char			*turn_flpoint_to_str(long double ld, char base,
		t_printf *tprintf);
int				long_math_strlen(t_dl_lst *lst, t_printf *tprintf, t_sem sem);
char			*turn_dl_lst_to_str(t_dl_lst *lst, t_printf tprintf,
		t_sem sem);
void			round_up_dl_lst(t_dl_lst **lst, int precision);
t_dl_lst		*long_math_sum(t_dl_lst *nbr1, t_dl_lst *nbr2);
void			long_math_sum_calc(t_dl_lst *nbr1, t_dl_lst **nbr2);
void			long_math_sum_add_rest(t_dl_lst *nbr1, char rest);
t_dl_lst		*long_math_mult(t_dl_lst *nbr1, t_dl_lst *nbr2);
t_dl_lst		*long_math_sqr(int nbr, char base, int rank);

#endif
