/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:09:11 by hsalah            #+#    #+#             */
/*   Updated: 2024/10/26 12:42:58 by hsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

// init the position and direction of the ray for a screen column
void	set_ray_pos(t_all *all, int x)
{
	all->ray.camera_x = 2 * x / (double)all->info.x_size - 1;
	all->ray.ray_dir_x = all->ray.dir_x + all->ray.plane_x * all->ray.camera_x;
	all->ray.ray_dir_y = all->ray.dir_y + all->ray.plane_y * all->ray.camera_x;
	all->ray.map_x = (int)all->ray.pos_x;
	all->ray.map_y = (int)all->ray.pos_y;
}

// sets the length of each step of the ray in the grid in x + y directions
void	set_ray_len(t_ray *ray)
{
	ray->delta_dist_y = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_x = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_y;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_y;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_x;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_x;
	}
}

// use DDA to advance the ray until it collides with a wall
void	perform_dda(t_all *all)
{
	while (all->ray.hit == 0)
	{
		if (all->ray.side_dist_x < all->ray.side_dist_y)
		{
			all->ray.side_dist_x += all->ray.delta_dist_y;
			all->ray.map_x += all->ray.step_x;
			all->ray.side = 0;
		}
		else
		{
			all->ray.side_dist_y += all->ray.delta_dist_x;
			all->ray.map_y += all->ray.step_y;
			all->ray.side = 1;
		}
		if (all->info.map[all->ray.map_x][all->ray.map_y] == '1')
			all->ray.hit = 1;
	}
}

// calculates the wall projection on the screen based on the distance
void	set_projection(t_ray *ray, t_info *info)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - ray->pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - ray->pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(info->y_size / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + info->y_size / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + info->y_size / 2;
	if (ray->draw_end >= info->y_size)
		ray->draw_end = info->y_size - 1;
}
