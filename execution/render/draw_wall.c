/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 16:37:18 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/04 16:37:18 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	fill_column(t_cub3d *cub3d, t_col *col)
{
	int	y;

	y = col->y_start;
	while (y < col->y_end)
	{
		pixel_put(&cub3d->img, col->x, y, col->color);
		y++;
	}
}

void	draw_textured_column(t_cub3d *cub3d, t_tex_col *tc)
{
	int	y;
	int	tex_y;

	y = tc->y_start;
	while (y <= tc->y_end)
	{
		tex_y = (int)tc->tex_pos % tc->tex->height;
		tc->tex_pos += tc->step;
		pixel_put(&cub3d->img, tc->x, y,
			get_tex_pixel(tc->tex, tc->tex_x, tex_y));
		y++;
	}
}

void	draw_ceiling(t_cub3d *cub3d, t_ray *ray, int x)
{
	t_col	col;

	col.x = x;
	col.y_start = 0;
	col.y_end = ray->draw_start;
	col.color = cub3d->textures->ceil_color;
	fill_column(cub3d, &col);
}

void	draw_floor(t_cub3d *cub3d, t_ray *ray, int x)
{
	t_col	col;

	col.x = x;
	col.y_start = ray->draw_end + 1;
	col.y_end = WIN_HEIGHT;
	col.color = cub3d->textures->floor_color;
	fill_column(cub3d, &col);
}

void	draw_wall_slice(t_cub3d *cub3d, t_ray *ray, int x)
{
	t_tex_col	tc;
	double		wall_x;

	draw_ceiling(cub3d, ray, x);
	draw_floor(cub3d, ray, x);
	tc.tex = get_texture(cub3d, ray);
	wall_x = get_wall_x(cub3d->player, ray);
	tc.tex_x = get_tex_x(tc.tex, ray, wall_x);
	tc.x = x;
	tc.y_start = ray->draw_start;
	tc.y_end = ray->draw_end;
	set_tex_step(&tc, ray);
	draw_textured_column(cub3d, &tc);
}
