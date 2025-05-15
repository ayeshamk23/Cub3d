/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:47:24 by hsalah            #+#    #+#             */
/*   Updated: 2024/10/22 07:42:55 by hsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	show_img(t_all *all)
{
	mlx_put_image_to_window(&(all->img.mlx), all->img.win, all->img.img, 0, 0);
	return (0);
}

int	file_to_img(t_img *img, char *filename)
{
	img->mlx = mlx_init();
	if (!(img->mlx))
		return (error_msg("Creating mlx pointer failed"));
	if (ft_strstr(filename, ".xpm"))
		img->img = mlx_xpm_file_to_image(img->mlx, filename, &(img->width),
				&(img->height));
	else if (ft_strstr(filename, ".png"))
		img->img = mlx_png_file_to_image(img->mlx, filename, &(img->width),
				&(img->height));
	if (!(img->img))
	{
		red();
		printf("\n\"%s\" does not exist.\n\n", filename);
		reset();
		return (1);
	}
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	return (0);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
