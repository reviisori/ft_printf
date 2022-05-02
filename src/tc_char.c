/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:06:47 by altikka           #+#    #+#             */
/*   Updated: 2022/05/02 16:11:31 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "vec.h"

int	tc_char(t_vec *dest, t_stat *attr)
{
	size_t	len;
	char	type;

	len = dest->len;
	type = attr->type;
	ft_putendl("CHAR - nothing here yet");
	return (1);
}
