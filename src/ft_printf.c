/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:38:37 by altikka           #+#    #+#             */
/*   Updated: 2022/04/27 18:22:54 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
													[|]
#	%[ $ ][ flags ][width][.precision][  lenght  ]conversion
#	       '#-+ 0'	all	   !c & !p	  			  c s p
#									   hh,h,l,ll  d i o u x X
#									   l,L	      f

*/

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*p;
	int		len;

	va_start(ap, format);
	len = print_shop(&p, format, ap);
	va_end(ap);
	if (len < 0)
	{
		ft_putendl("print shop burned down");
		return (len);
	}
	write(1, p, len);
	free(p);
	return (len);
}
