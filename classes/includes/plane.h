/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:47:41 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 14:47:59 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "scene.h"

typedef struct	s_plane
{
	char		identifier[2];
	t_point		point;
	t_3dvector	vector;
	float		side_size;
	t_color		color;
}				t_plane;

#endif
