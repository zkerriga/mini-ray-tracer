/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:00:17 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 15:00:23 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "scene.h"

typedef struct	s_cylinder
{
	char		identifier[2];
	t_point		point;
	t_3dvector	vector;
	float		diameter;
	float		height;
	t_color		color;
}				t_cylinder;

#endif
