/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:16:57 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 16:17:14 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolution.h"
#include "libft.h"

t_resolution	*new_resolution(char *line)
{
	t_resolution	*resolution;

	resolution = (t_resolution *)malloc_gc(sizeof(t_resolution));
	resolution->identifier[0] = 'R';
	while
}
