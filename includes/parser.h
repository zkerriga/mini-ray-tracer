/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:28:45 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/18 20:28:51 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "scene.h"
# include <fcntl.h>
# include "get_new_line.h"

t_scene	*parser(char *path, char *line);
t_bool	match(char *str, char *format);
void	parser_error(t_resolution *resolution, t_ambient *ambient,
						t_list *all_obj, t_dlist *cameras);
t_dlist	*ft_dlstnew_gc(void *content);
t_list	*ft_lstnew_gc(void *content);

#endif
