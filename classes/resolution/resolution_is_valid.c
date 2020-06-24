/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_is_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:57:24 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 16:57:29 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "basic_structures.h"

t_bool	resolution_is_valid(char *line)
{
	line = ft_next(line);
	if (!check_int(line) || ft_atoi(line) < 1)
		return (FALSE);
	line = ft_next(line);
	if (!check_int(line) || ft_atoi(line) < 1)
		return (FALSE);
	if (*line == '\0')
		return (TRUE);
	else
		return (FALSE);
}
