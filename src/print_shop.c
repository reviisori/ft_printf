/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:36:48 by altikka           #+#    #+#             */
/*   Updated: 2022/05/12 14:34:21 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_shop(char **str, const char *format, va_list ap)
{
	t_vec	print;
	t_stat	info;
	int		ret;

	if (ft_vecnew(&print, 1, sizeof(char)) < 0)
		return (-1);
	init_stats(&info, ap);
	ret = press(&print, format, info);
	if (ret < 0)
	{
		ft_vecdel(&print);
		return (-1);
	}
	*str = print.data;
	va_end(info.ap);
	return (print.len);
}
