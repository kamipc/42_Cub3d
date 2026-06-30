/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:10:29 by sade-ara          #+#    #+#             */
/*   Updated: 2026/06/30 14:24:23 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_img *img, t_square square)
{
	int	i;
	int	j;

	j = 0;
	while (j < square.size)
	{
		i = 0;
		while (i < square.size)
		{
			pixel_put(img, square.x + i, square.y + j, square.color);
			i++;
		}
		j++;
	}
}

void	clear_image(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_background(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				pixel_put(&cub3d->img, x, y, 0x87CEEB);
			else
				pixel_put(&cub3d->img, x, y, 0x5C4033);
			x++;
		}
		y++;
	}
}

void	draw_player(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			pixel_put(&cub3d->img, (int)cub3d->player->y + x,
				(int)cub3d->player->y + y, 0xFF0000);
			x++;
		}
		y++;
	}
}
