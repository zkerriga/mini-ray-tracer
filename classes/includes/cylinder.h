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

# include "basic_structures.h"

typedef struct	s_cylinder
{
	char		identifier[2];
	void		(*del)(struct s_cylinder *);
	t_rgbvec	color;
	t_point		point;
	t_3dvector	vector;
	float		diameter;
	float		height;
}				t_cylinder;

t_cylinder		*new_cylinder(char *line);

#endif
