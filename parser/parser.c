/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:28:20 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/18 20:28:28 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

static void	manager(t_list **all_obj, char *line)
{
	if (line[0] == 's' && line[1] == 'p')
		ft_lstadd_front(all_obj, ft_lstnew(new_sphere(line)));
	else if (line[0] == 'p' && line[1] == 'l')
		ft_lstadd_front(all_obj, ft_lstnew(new_plane(line)));
	else if (line[0] == 's' && line[1] == 'q')
		ft_lstadd_front(all_obj, ft_lstnew(new_square(line)));
	else if (line[0] == 'c' && line[1] == 'y')
		ft_lstadd_front(all_obj, ft_lstnew(new_cylinder(line)));
	else if (line[0] == 't' && line[1] == 'r')
		ft_lstadd_front(all_obj, ft_lstnew(new_triangle(line)));
	else if (line[0] == 'c')
		ft_lstadd_front(all_obj, ft_lstnew(new_camera(line)));
	else if (line[0] == 'l')
		ft_lstadd_front(all_obj, ft_lstnew(new_light(line)));
	else
		ft_exit(INVALID_INPUT);

}

t_scene		*parser(char *path, char *line)
{
	t_scene			*scene;
	t_resolution	*resolution;
	t_ambient		*ambient;
	t_list			*all_obj;
	int				fd;

	fd = open(path, O_RDONLY);
	if (fd < 3)
		ft_exit(INVALID_DESCRIPTOR);
	all_obj = NULL;
	ambient = NULL;
	resolution = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) > 3)
		{
			if (line[0] == 'R')
				resolution = new_resolution(line);
			else if (line[0] == 'A')
				ambient = new_ambient(line);
			else
				manager(&all_obj, line);
		}
		free(line);
	}
	free(line);
	if (!ambient || !resolution)
		ft_exit(INVALID_INPUT);
	scene = new_scene(resolution, ambient, all_obj);
	return (scene);
}
