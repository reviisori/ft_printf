/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:08:42 by altikka           #+#    #+#             */
/*   Updated: 2022/04/27 19:53:50 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_stat
{
	va_list			ap;
	long			value;
	char			type;
	int				sign;
	unsigned int	is_signed;	// : 1?
	unsigned int	flags;		// : 5?
	unsigned int	width;
	unsigned int	preci;
	unsigned int	preci_on;	// : 1?
	unsigned int	lenght;		// : ??
	char			pad;
}			t_stat;

/*

typedef int	(*t_STRUCT)(TYPE *, TYPE *, [...]);

t_STRUCT (*)NAME[4] = {
	add,
	sub,
	mult,
	divide
};

*/

int		ft_printf(const char *format, ...);
int		print_shop(char **str, const char *format, va_list ap);
int		press(t_vec *dest, const char *format, t_stat attr);

#endif
