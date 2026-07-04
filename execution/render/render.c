/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:10:02 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/02 18:00:21 by sade-ara         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/cub3d.h"

int	render(t_cub3d *cub3d)
{
	clear_image(&cub3d->img, 0);
	draw_background(cub3d);
	cast_rays(cub3d);
	draw_player(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img,
		0, 0);
	return (0);
}

// void	start_game(t_cub3d *cub3d)
// {
// 	init_window(cub3d);
// 	init_image(cub3d);
// 	load_textures(cub3d);

// 	cub3d->player->x = WIN_WIDTH / 2;
// 	cub3d->player->y = WIN_HEIGHT / 2;

// 	mlx_hook(cub3d->win, 17, 0, close_win, cub3d);
// 	mlx_hook(cub3d->win, 2, 1L << 0, key_press, cub3d);
// 	mlx_loop_hook(cub3d->mlx, render, cub3d);
// 	mlx_loop(cub3d->mlx);
// }

static void	init_test_map(t_cub3d *cub3d)
{
	static char	*test_map[] = {
		"1111111111",
		"1000000001",
		"1000000001",
		"1000000001",
		"1111111111",
		NULL
	};

	cub3d->map->map = test_map;
}

// start_game teste sem parsing
void	start_game(t_cub3d *cub3d)
{
	init_window(cub3d);
	init_image(cub3d);

	init_test_map(cub3d);

	cub3d->textures->NO = "maps/textures/north.xpm";
	cub3d->textures->SO = "maps/textures/south.xpm";
	cub3d->textures->EA = "maps/textures/east.xpm";
	cub3d->textures->WE = "maps/textures/west.xpm";

	load_textures(cub3d);

	cub3d->player->x = 2.5;
	cub3d->player->y = 2.5;
	cub3d->player->dir_x = 0;
	cub3d->player->dir_y = -1;
	cub3d->player->plane_x = 0.66;
	cub3d->player->plane_y = 0;

	mlx_hook(cub3d->win, 17, 0, close_win, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, key_press, cub3d);
	mlx_loop_hook(cub3d->mlx, render, cub3d);
	mlx_loop(cub3d->mlx);
}
