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

typedef struct	s_any_object
{
	char		identifier[2];
	void		(*del)(struct s_any_object *);
}				t_any_object;

char	*ft_next(char *line);

#endif
