/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_is_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:26:58 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 17:27:10 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_structures.h"

t_bool	triangle_is_valid(char *line)
{
	line = ft_next(line);
	if (!check_coordinates(&line))
		return (FALSE);
	if (!check_coordinates(&line))
		return (FALSE);
	if (!check_coordinates(&line))
		return (FALSE);
	if (!check_color(&line))
		return (FALSE);
	if (*line == '\0')
		return (TRUE);
	else
		return (FALSE);
}
