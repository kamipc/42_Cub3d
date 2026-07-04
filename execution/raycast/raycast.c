/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:09:54 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/02 17:45:22 by sade-ara         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/cub3d.h"

void	calc_wall_slice(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	if (ray->perp_wall_dist <= 0)
		ray->perp_wall_dist = 0.0001;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	cast_rays(t_cub3d *cub3d)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(cub3d, &ray, x);
		dda(cub3d, &ray);
		calc_wall_slice(&ray);
		draw_wall_slice(cub3d, &ray, x);
		x++;
	}
}
