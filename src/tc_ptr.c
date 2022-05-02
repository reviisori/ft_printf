/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:12:42 by altikka           #+#    #+#             */
/*   Updated: 2022/05/02 16:12:56 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "vec.h"

int	tc_ptr(t_vec *dest, t_stat *attr)
{
	size_t	len;
	char	type;

	len = dest->len;
	type = attr->type;
	ft_putendl("PTR - nothing here yet");
	return (1);
}
