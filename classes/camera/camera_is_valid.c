/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:52:35 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 14:52:41 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "basic_structures.h"

t_bool	camera_is_valid(char *line)
{
	int	fov;

	line = ft_next(line);
	if (!check_coordinates(&line))
		return (FALSE);
	if (!check_vector(&line))
		return (FALSE);
	if (!check_int(line))
		return (FALSE);
	if ((fov = ft_atoi(line)) < 0 || fov > 180)
		return (FALSE);
	if (*ft_next(line) == '\0')
		return (TRUE);
	else
		return (FALSE);
}
