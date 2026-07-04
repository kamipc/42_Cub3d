/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 17:05:19 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/04 17:05:19 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

t_img	*get_texture(t_cub3d *cub3d, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (&cub3d->textures->img_we);
		return (&cub3d->textures->img_ea);
	}
	if (ray->step_y > 0)
		return (&cub3d->textures->img_so);
	return (&cub3d->textures->img_no);
}

double	get_wall_x(t_player *player, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = player->y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	get_tex_x(t_img *tex, t_ray *ray, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)tex->width);
	if (ray->side == 0 && ray->step_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->step_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

int	get_tex_pixel(t_img *tex, int x, int y)
{
	char	*pixel;

	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(int *)pixel);
}
