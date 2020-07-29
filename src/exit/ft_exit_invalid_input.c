/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_invalid_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 23:41:25 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 23:41:32 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "libft.h"

void	ft_exit_invalid_input(void)
{
	ft_putendl_fd("The scene description from the file is incorrect!", 1);
	free_gc(NULL);
	exit(0);
}
