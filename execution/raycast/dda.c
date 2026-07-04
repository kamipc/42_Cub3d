/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:10:40 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/02 17:11:07 by sade-ara         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/cub3d.h"

static void	step_ray(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

void	dda(t_cub3d *cub3d, t_ray *ray)
{
	while (!ray->hit)
	{
		step_ray(ray);
		if (cub3d->map->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}
