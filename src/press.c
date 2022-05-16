/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:21:41 by altikka           #+#    #+#             */
/*   Updated: 2022/05/16 14:26:18 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//del
			//printf("preci: %d\n", info.preci);//del
			//printf("on/off: %d\n", info.preci_on);//del
			//printf("fptr: %s\n", p);//del


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
			inves_width(&p, &info);
			inves_preci(&p, &info);
			inves_lenght(&p, &info);
			if (press_type(dest, &p, &info) < 0)
				return (-1);
			format = p;
		}
	}
	if (ft_vecncat(dest, format, (p - format)) < 0)
		return (-1);
	return (1);
}
