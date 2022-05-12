/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inves_preci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:38:17 by altikka           #+#    #+#             */
/*   Updated: 2022/05/12 14:53:03 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	inves_preci(const char **fptr, t_stat *info)
{
	size_t	hop;

	if (**fptr != '.')
		return (-1);
	(*fptr)++;
	info->preci_on = true;
	info->preci = (unsigned int ) ft_atoi(*fptr);
	if (info->preci)
	{
		hop = ft_anylen(info->preci, 10, 1);
		(*fptr) = (*fptr) + hop;
	}
	while (**fptr == '0')
		(*fptr)++;
	return (1);
}
