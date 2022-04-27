/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:36:48 by altikka           #+#    #+#             */
/*   Updated: 2022/04/27 19:53:52 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//SEPERATE IN OWN .C
int	press(t_vec *dest, const char *format, t_stat attr)
{
	char	*p;

	p = format;
	while (*p)
	{
		if (*p == '%')
		{
			//FT_WHAT_NOW;
			return (-1);
		}
		ft_vecpush(dest, p);
		p++;
	}
	ft_vecpush(dest, '\0');
	return (0);
}

int	print_shop(char **str, const char *format, va_list ap)
{
	t_vec	print;
	t_stat	attr;
	int		ret;

	if (ft_vecnew(&print, 1, sizeof(char)) < 0)
		return (-1);
	//init attributes
	ret = press(&print, format, attr);
	if (ret < 0)
		return (ret);
	*str = print.data;
	va_end(attr.ap);
	return (print.len - 1);
}
