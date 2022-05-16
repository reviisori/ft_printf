/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inves_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:53:49 by altikka           #+#    #+#             */
/*   Updated: 2022/05/16 21:48:58 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	inves_width(const char **fptr, t_stat *info)
{
	size_t	hop;

	if (!(ft_isdigit(**fptr)))
		return (-1);
	info->width = (unsigned int ) ft_atoi(*fptr);
	if (info->width)
	{
		hop = ft_anylen(info->width, 10, 1);
		(*fptr) = (*fptr) + hop;
	}
	while (**fptr == '0')
		(*fptr)++;
	return (1);
}
