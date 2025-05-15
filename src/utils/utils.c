/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:47:29 by hsalah            #+#    #+#             */
/*   Updated: 2024/10/22 07:43:04 by hsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	put_hor_full(t_all *all, int y, int color)
{
	int	i;

	i = 0;
	while (i < all->info.x_size)
	{
		put_pixel((&all->img), i, y, color);
		i++;
	}
}

int	is_notmap(char c)
{
	if (!c)
		return (1);
	if (c == ' ' || c == '\n')
		return (1);
	else
		return (0);
}

int	free_all(t_info *info, int stage)
{
	if (stage)
		free(info->full_file);
	free(info->no_path);
	free(info->so_path);
	free(info->we_path);
	free(info->ea_path);
	free_2darray(info->map);
	return (1);
}
