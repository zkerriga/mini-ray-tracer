/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:12:29 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 15:12:34 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLUTION_H
# define RESOLUTION_H

# include "scene.h"

typedef struct	s_resolution
{
	char		identifier[2];
	int			x_size;
	int			y_size;
}				t_resolution;

#endif
