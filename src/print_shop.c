/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:36:48 by altikka           #+#    #+#             */
/*   Updated: 2022/04/28 17:07:14 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//SEPERATE IN OWN .C
int	press(t_vec *dest, const char *format, t_stat attr)
{
	const char	*p;

	attr.value = 666;	//init_stats(&attr);
	p = format;
	while (*p)
	{
		if (*p == '%')
		{
			ft_vecncat(dest, format, (p - format));
			//FT_WHAT_NOW;
			format = p;
		}
		p++;
	}
	ft_vecncat(dest, format, (p - format));
	return (0);
}

int	print_shop(char **str, const char *format, va_list ap)
{
	t_vec	print;
	t_stat	attr;
	int		ret;

	va_end(ap);			//REMOVE
	if (ft_vecnew(&print, 1, sizeof(char)) < 0)
		return (-1);
	attr.value = 666;	//init_stats(&attr);
	ret = press(&print, format, attr);
	if (ret < 0)
		return (ret);
	*str = print.data;
	va_end(attr.ap);
	return (print.len);
}
