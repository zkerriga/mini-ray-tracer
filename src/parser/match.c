/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:17:25 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/23 18:17:26 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** The function determines whether a string matches a format string,
** taking into account the special '*' character.
*/

t_bool	match(char *str, char *format)
{
	if (!*str && !*format)
		return (TRUE);
	else if (*str == *format && *str != '*')
		return (match(str + 1, format + 1));
	else if (*str == '*' && *format == '*')
		return (match(str + 1, format));
	else if (*format == '*' && !*str)
		return (match(str, format + 1));
	else if (*format == '*' && *format && *str)
		return (match(str, format + 1) || match(str + 1, format));
	else
		return (FALSE);
}
