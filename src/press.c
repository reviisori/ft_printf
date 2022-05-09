/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:21:41 by altikka           #+#    #+#             */
/*   Updated: 2022/05/09 13:57:58 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	press(t_vec *dest, const char *format, t_stat info)
{
	const char	*p;

	p = format;
	while (*p)
	{
		if (*p++ == '%')
		{
			if (!*p)
				return (1);
			if (ft_vecncat(dest, format, ((p - 1) - format)) < 0)
				return (-1);
			reset_stats(&info);
			//[--$--]
			//  [flags]
			//	  [width]
			//		[.preci]
			//		  [lenght]
			if (press_type(dest, &p, &info) < 0)
				return (-1);
			format = p;
		}
	}
	if (ft_vecncat(dest, format, (p - format)) < 0)
		return (-1);
	return (1);
}
