/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:11:33 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/02 17:21:44 by sade-ara         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../headers/cub3d.h"

static void	calc_delta_dist(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
}

static void	calc_step_side(t_player *p, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (p->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - p->x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (p->y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - p->y)
			* ray->delta_dist_y;
	}
}

void	init_ray(t_cub3d *cub3d, t_ray *ray, int x)
{
	t_player	*p;

	p = cub3d->player;
	ray->camera_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
	ray->ray_dir_x = p->dir_x + p->plane_x * ray->camera_x;
	ray->ray_dir_y = p->dir_y + p->plane_y * ray->camera_x;
	ray->map_x = (int)p->x;
	ray->map_y = (int)p->y;
	ray->hit = 0;
	calc_delta_dist(ray);
	calc_step_side(p, ray);
}
