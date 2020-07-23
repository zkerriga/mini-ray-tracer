/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:48:00 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/23 18:48:02 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_description(void)
{
	ft_putstr_fd("DESCRIPTION\n\
\tThis project is the beginning of the study of \"Ray Tracing\" technology!\n\
\tThis program is able to create three-dimensional graphics from a text\n\
\tdescription of all scene parameters. A simple version of ray tracing\n\
\tallows you to determine the color of each pixel well, which adds realism\n\
\tto the scene!\n\n", 1);
}

static void	print_usage(void)
{
	ft_putstr_fd("USAGE\n\
\t./miniRT [FILE_PATH] [OPTIONS]\n\
\tThe file must have the .rt extension and the scene description must\n\
\tcontain at least Ambient and Resolution! Options is optional.\n\n", 1);
}

static void	print_options(void)
{
	ft_putstr_fd("OPTIONS\n\
\t-h --help\t\tShows this help.\n\
\t-s --save\t\tAllows you to save the render result in a bmp-image.\n\n", 1);
}

static void	print_author(void)
{
	ft_putstr_fd("AUTHOR\n\tMade with love! Zkerriga.\n\n", 1);
}

void		show_help(void)
{
	ft_putstr_fd("\nNAME\n\tminiRT\n\n", 1);
	print_description();
	print_usage();
	print_options();
	print_author();
}
