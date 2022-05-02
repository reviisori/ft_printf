/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:21:41 by altikka           #+#    #+#             */
/*   Updated: 2022/04/29 15:40:02 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	press(t_vec *dest, const char *format, t_stat attr)
{
	const char	*p;

	p = format;
	while (*p)
	{
		if (*p == '%')
		{
			if (ft_vecncat(dest, format, (p - format)) < 0)
				return (-1);
			reset_stats(&attr);
			//[--$--]
			//  [flags]
			//	  [width]
			//		[.preci]
			//		  [lenght]
			press_type(dest, &p, &attr);
			format = p;
		}
		p++;
	}
	if (ft_vecncat(dest, format, (p - format)) < 0)
		return (-1);
	return (0);
}
