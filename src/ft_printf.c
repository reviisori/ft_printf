/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:38:37 by altikka           #+#    #+#             */
/*   Updated: 2022/05/30 11:57:19 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*p;
	int		len;

	va_start(ap, format);
	len = ft_vasprintf(&p, format, ap);
	va_end(ap);
	if (len < 0)
	{
		ft_putendl("*ERROR*: ft_vasprintf returned -1");
		return (len);
	}
	write(1, p, len);
	free(p);
	return (len);
}
