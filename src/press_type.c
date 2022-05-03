/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:17:17 by altikka           #+#    #+#             */
/*   Updated: 2022/05/02 16:26:54 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_index(const char c)
{
	char	*p;

	p = ft_strcasechr(TYPES, c);
	if (!p)
		return (-1);
	return (p - TYPES);
}

int	press_type(t_vec *dest, const char **fptr, t_stat *attr)
{
	t_jump	disp;
	int		i;

	(*fptr)++;
	attr->type = **fptr;
	(*fptr)++;
	i = get_index(attr->type);
	if (i < 0)
	{
		ft_putendl("*ERROR*: conversion not supported");
		return (-1);
	}
	disp = g_jump[i];
	return (disp(dest, attr));
}
