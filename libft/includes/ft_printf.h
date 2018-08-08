/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:51:45 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/21 04:21:27 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** <--- INCLUDES --->
*/

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <inttypes.h>
# include "libft.h"

/*
** <--- DEFINES --->
*/

# define SM_SHORT   1
# define SM_SHORT2  2
# define SM_LONG	3
# define SM_LONG2   4
# define SM_MINT	5
# define SM_SIZE_T  6

/*
** <--- STRUCTS --->
*/

typedef struct	s_pf_st
{
	char		*format;
	char		c;
	int			length;
	int			m_length;
	int			precision;
	int			sm;
	int			fw;
	int			is_min;
	int			is_hash;
	int			is_zero;
	int			is_plus;
	int			is_space;
	int			pr_min;
	va_list		list;
}				t_pf_st;

/*
** <--- PROTOTYPES --->
*/

/*
** ft_printf.c
*/

int				ft_printf(const char *format, ...);

/*
** parse_opt.c
*/

void			parse_flags(t_pf_st *t_st);
void			parse_width_n_precision(t_pf_st *t_st);
void			parse_size_mod(t_pf_st *t_st);
void			parse_conversion(t_pf_st *t_st);

/*
** print_nbr.c
*/

int				print_int(t_pf_st *t_st, int base);
int				print_uint(t_pf_st *t_st, int base, int up);
int				print_lint(t_pf_st *t_st, int base);
int				print_ptr(t_pf_st *t_st);
int				print_chr(t_pf_st *t_st, char c);

/*
** print_wchr.c
*/

int				print_wchr(wint_t num);

/*
** print_str.c
*/

int				print_str(t_pf_st *t_st, char *str, int prec);
int				print_char(char c);
int				print_nchar(char c, int n);

/*
** print_wstr.c
*/

int				print_wstr(t_pf_st *t_st, wchar_t *str, int prec);

/*
** print.c
*/

int				is_upper(int c);
int				precision(t_pf_st *t_st, int len);
void			print(t_pf_st *t_st);

/*
** utils.c
*/

int				num_padding(t_pf_st *t_st, int side, int len,
				unsigned long value);
void			check_flags(t_pf_st *t_st, int len,
				unsigned long value, int side);
void			apply_flags(t_pf_st *t_st, unsigned long value);

/*
** itoa_utils.c
*/
int				ft_itoa_base(t_pf_st *t_st, unsigned long value,
				unsigned long base, int up);
int				ft_itoa_count(unsigned long value, unsigned long base);

#endif
