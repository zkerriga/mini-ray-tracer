/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:54:22 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 16:54:27 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_structures.h"

t_bool	plane_is_valid(char *line)
{
	line = ft_next(line);
	if (!check_coordinates(&line))
		return (FALSE);
	if (!check_vector(&line))
		return (FALSE);
	if (!check_color(&line))
		return (FALSE);
	if (*line == '\0')
		return (TRUE);
	else
		return (FALSE);
}
