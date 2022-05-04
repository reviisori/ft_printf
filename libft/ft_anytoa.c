/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anytoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:18:59 by altikka           #+#    #+#             */
/*   Updated: 2022/05/04 12:43:56 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

static char	*set_case(int casing)
{
	if (casing)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

static char	*anytoacpy(char *dst, uintmax_t n, int base, char *conv)
{
	if (n / base != 0)
		dst = anytoacpy(dst, (n / base), base, conv);
	*dst++ = conv[n % base];
	*dst = '\0';
	return (dst);
}

char	*ft_anytoa(uintmax_t n, int base, int sign, int casing)
{
	char	*ptr;
	char	*conv;
	int		offset;

	if (base < 2 || base > 16)
		return (NULL);
	ptr = (char *)malloc(sizeof(*ptr) * (ft_anylen(n, base, sign) + 1));
	if (!ptr)
		return (NULL);
	conv = set_case(casing);
	offset = 0;
	if (sign == -1)
	{
		*ptr++ = '-';
		offset++;
		anytoacpy(ptr, n, base, conv);
	}
	else
		anytoacpy(ptr, n, base, conv);
	return (ptr - offset);
}
