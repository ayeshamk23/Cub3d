/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:47:38 by hsalah            #+#    #+#             */
/*   Updated: 2024/10/22 07:43:28 by hsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	main(int argc, char *argv[])
{
	t_all	all;

	ft_bzero(&all, sizeof(all));
	if (init_input(&all, argc, argv[1])
		|| init_textures(&all)
		|| init_mlx(&all)
		|| init_raycaster(&all)
		|| draw_img(&all)
		|| show_img(&all))
		return (1);
	mlx_hook(all.img.win, DESTROY, 0, &destroy_window, &all);
	mlx_hook(all.img.win, PRESS, 0, &key_pressed, &all);
	mlx_hook(all.img.win, RELEASE, 0, &key_released, &all);
	mlx_loop_hook(all.img.mlx, &check_move, &all);
	mlx_loop(all.img.mlx);
	return (0);
}
