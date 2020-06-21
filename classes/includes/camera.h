/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:19:23 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 15:19:31 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "basic_structures.h"

typedef struct	s_camera
{
	char		identifier[2];
	t_point		point;
	t_3dvector	vector;
	int			fov;
	void		(*del)(struct s_camera *);
}				t_camera;

t_camera		*new_camera(char *line);

#endif
