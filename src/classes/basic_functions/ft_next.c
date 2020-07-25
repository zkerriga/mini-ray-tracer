/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:43:51 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 16:43:57 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_next(char *line)
{
	while (*line && !(ft_isspace(*line) || *line == ','))
		++line;
	while (ft_isspace(*line) || *line == ',')
		++line;
	return (line);
}
