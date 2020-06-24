/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:51:10 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 16:51:15 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "basic_structures.h"

t_bool	light_is_valid(char *line)
{
	line = ft_next(line);
	if (!check_coordinates(&line))
		return (FALSE);
	if (!check_float(line))
		return (FALSE);
	if (!ft_float_between(ft_atof(line), 0.0f, 1.0f))
		return (FALSE);
	line = ft_next(line);
	if (!check_color(&line))
		return (FALSE);
	if (*line == '\0')
		return (TRUE);
	else
		return (FALSE);
}
