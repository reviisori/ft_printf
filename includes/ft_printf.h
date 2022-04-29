/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:08:42 by altikka           #+#    #+#             */
/*   Updated: 2022/04/29 17:49:23 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "vec.h"

typedef struct s_stat
{
	va_list			ap;
	long			value;
	int				sign;
	unsigned int	is_signed;	// : 1?
	unsigned int	flags;		// : 5?
	unsigned int	width;
	unsigned int	preci;
	unsigned int	preci_on;	// : 1?
	unsigned int	lenght;		// : 3?
	char			type;
	char			pad;
}			t_stat;

/*

int		tc_char(t_vec *dest, t_stat attr);
int		tc_num(t_vec *dest, t_stat attr);
int		tc_ptr(t_vec *dest, t_stat attr);
int		tc_str(t_vec *dest, t_stat attr);

typedef int	(*t_STRUCT)(TYPE *, TYPE *);

t_STRUCT (*)NAME[4] = {
	tc_char,
	tc_num,
	tc_ptr,
	tc_str
};

*/

int		ft_printf(const char *format, ...);
int		print_shop(char **str, const char *format, va_list ap);
int		press(t_vec *dest, const char *format, t_stat attr);
void	init_stats(t_stat *attr, va_list ap);
void	reset_stats(t_stat *attr);

#endif
