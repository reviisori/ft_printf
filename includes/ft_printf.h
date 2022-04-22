/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:08:42 by altikka           #+#    #+#             */
/*   Updated: 2022/04/22 17:58:37 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_stats
{
	va_list			ap;
	long			value;
	char			tag;
	int				sign;
	unsigned int	width;
	unsigned int	lenght;
	unsigned int	flags;
	unsigned int	preci;
	//...
	char			pad;
}			t_stats;



int	ft_printf(const char *format, ...);



#endif
