/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:09:18 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/02 17:42:40 by sade-ara         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/cub3d.h"

static int	get_wall_color(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (0x008000);
		return (0x00CC00);
	}
	if (ray->step_y > 0)
		return (0xCC0000);
	return (0xFF4444);
}

static int	draw_ceiling(t_cub3d *cub3d, int x, int end)
{
	int	y;

	y = 0;
	while (y < end)
	{
		pixel_put(&cub3d->img, x, y,
			cub3d->textures->ceil_color);
		y++;
	}
	return (y);
}

static int	draw_wall(t_cub3d *cub3d, t_ray *ray,
	int x, int color)
{
	int	y;

	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		pixel_put(&cub3d->img, x, y, color);
		y++;
	}
	return (y);
}

static void	draw_floor(t_cub3d *cub3d, int x, int start)
{
	while (start < WIN_HEIGHT)
	{
		pixel_put(&cub3d->img, x, start,
			cub3d->textures->floor_color);
		start++;
	}
}

void	draw_wall_slice(t_cub3d *cub3d, t_ray *ray, int x)
{
	int	color;
	int	y;

	color = get_wall_color(ray);
	y = draw_ceiling(cub3d, x, ray->draw_start);
	y = draw_wall(cub3d, ray, x, color);
	draw_floor(cub3d, x, y);
}
