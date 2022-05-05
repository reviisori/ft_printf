/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:08:42 by altikka           #+#    #+#             */
/*   Updated: 2022/05/05 12:25:05 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include "handl.h"
# include "vec.h"

# define TYPES "cdfiopsux"
# define FLAGS "#-+ 0"

typedef struct s_stat
{
	va_list			ap;
	long			val;
	int				sign;
	bool			is_signed;
	bool			hash;
	bool			dash;
	bool			plus;
	bool			space;
	bool			zero;
	unsigned int	width;
	unsigned int	preci;
	bool			preci_on;
	t_len			lenght;
	char			type;
	char			pad;
}			t_stat;

int		tc_char(t_vec *dest, t_stat *attr);
int		tc_dbl(t_vec *dest, t_stat *attr);
int		tc_num(t_vec *dest, t_stat *attr);
int		tc_ptr(t_vec *dest, t_stat *attr);
int		tc_str(t_vec *dest, t_stat *attr);

typedef int			(*t_jump)(t_vec *, t_stat *);

static const t_jump	g_jump[9] = {
	tc_char,	//c
	tc_num,		//d
	tc_dbl,		//f
	tc_num,		//i
	tc_num,		//o
	tc_ptr,		//p
	tc_str,		//s
	tc_num,		//u
	tc_num		//xX
};

int		ft_printf(const char *format, ...);
int		print_shop(char **str, const char *format, va_list ap);
int		press(t_vec *dest, const char *format, t_stat attr);
void	init_stats(t_stat *attr, va_list ap);
void	reset_stats(t_stat *attr);
int		set_base(const char c);
int		press_type(t_vec *dest, const char **fptr, t_stat *attr);

#endif
