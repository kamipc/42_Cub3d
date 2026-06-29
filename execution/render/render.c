/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:10:02 by sade-ara          #+#    #+#             */
/*   Updated: 2026/06/29 14:10:02 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	start_game(t_cub3d *cub3d)
{
	init_window(cub3d);
	init_image(cub3d);
	pixel_put(&cub3d->img, 100, 100, 0xFF0000);
	mlx_put_image_to_window(
		cub3d->mlx,
		cub3d->win,
		cub3d->img.img, 0, 0);
	mlx_hook(cub3d->win, 17, 0, close_win, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, key_press, cub3d);
	mlx_loop(cub3d->mlx);
}
