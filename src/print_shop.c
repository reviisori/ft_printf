/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:36:48 by altikka           #+#    #+#             */
/*   Updated: 2022/04/29 15:38:25 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_shop(char **str, const char *format, va_list ap)
{
	t_vec	print;
	t_stat	attr;
	int		ret;

	if (ft_vecnew(&print, 1, sizeof(char)) < 0)
		return (-1);
	init_stats(&attr, ap);
	ret = press(&print, format, attr);
	if (ret < 0)
		return (-1);
	*str = print.data;
	va_end(attr.ap);
	return (print.len);
}
