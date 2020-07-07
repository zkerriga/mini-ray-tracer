/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:44:28 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 15:44:32 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_STRUCTURES_H
# define BASIC_STRUCTURES_H

# define TRUE 1
# define FALSE 0

typedef char	t_bool;

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct	s_3dvector
{
	float		x;
	float		y;
	float		z;
}				t_3dvector;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct	s_rgbvec
{
	float		r;
	float		g;
	float		b;
}				t_rgbvec;

typedef struct	s_any_object
{
	char		identifier[2];
	void		(*del)(struct s_any_object *);
	float		(*solve)(struct s_any_object *, t_point *, t_3dvector *);
	t_3dvector	*(*get_n)(struct s_sphere *, t_point *);
	t_color		color;
}				t_any_object;

char	*ft_next(char *line);
t_bool	ft_float_between(float nbr, float down, float up);
t_bool	check_float(char *line);
t_bool	check_int(char *line);
t_bool	check_vector(char **line);
t_bool	check_color(char **line);
t_bool	check_coordinates(char **line);

#endif
