/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:08:42 by altikka           #+#    #+#             */
/*   Updated: 2022/05/16 15:39:47 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "handl.h"
# include "vec.h"

# define TYPES "cdfiopsux"
# define FLAGS "#-+ 0"

int			tc_char(t_vec *dest, t_stat *info);
int			tc_dbl(t_vec *dest, t_stat *info);
int			tc_num(t_vec *dest, t_stat *info);
int			tc_ptr(t_vec *dest, t_stat *info);
int			tc_str(t_vec *dest, t_stat *info);

typedef int			(*t_jump)(t_vec *, t_stat *);

static const t_jump	g_jump[9] = {
	tc_char,
	tc_num,
	tc_dbl,
	tc_num,
	tc_num,
	tc_ptr,
	tc_str,
	tc_num,
	tc_num
};

int			ft_printf(const char *format, ...);
int			print_shop(char **str, const char *format, va_list ap);
int			press(t_vec *dest, const char *format, t_stat info);
int			inves_width(const char **fptr, t_stat *info);
int			inves_preci(const char **fptr, t_stat *info);
int			inves_lenght(const char **fptr, t_stat *info);
int			press_type(t_vec *dest, const char **fptr, t_stat *info);
long double	round_dbl(long double val, unsigned int preci);
void		init_stats(t_stat *info, va_list ap);
void		reset_stats(t_stat *info);
int			set_base(const char c);

#endif
