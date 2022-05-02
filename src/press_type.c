//42-HEADER

#include "ft_printf.h"
#include "libft.h"

static int	get_index(const char c)
{
	char	type[];

	type = "cdfiopsux";	//define in .h?
	return (INDEX);		//YEP
}

int	press_type(t_vec *dest, const char **fptr, t_stat *attr)
{
	t_jump	disp;

	*fptr++;
	attr->type = *fptr;
	if (disp[get_index(attr->type)] < 0)
	{
		ft_putendl("error: conversion not supported");
		return (-1);
	}
	return (disp(dest, attr));
}
