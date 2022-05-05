/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:28:17 by altikka           #+#    #+#             */
/*   Updated: 2022/05/05 11:22:13 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDL_H

# define HANDL_H

typedef enum e_len
{
	null,
	hh,
	h,
	ll,
	l,
	L
}			t_len;

/*
 *
char	*handle_char(t_stat *attr);
char	*handle_short(t_stat *attr);
char	*handle_int(t_stat *attr);
char	*handle_long(t_stat *attr);

typedef char	*(*t_handler)(t_stat *);

static const t_handler g_handler[6] = {
	handle_int,
	handle_char,
	handle_short,
	handle_long,
	handle_long,
	handle_long
};
 *
 */

#endif
