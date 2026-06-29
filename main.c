/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:35:21 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/27 14:22:52 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

// main execution test

int	main(int ac, char **av)
{
	t_cub3d	*cub3d;

	(void)ac;
	(void)av;

	cub3d = init_cub3d();
	if (!cub3d)
		return (1);

	init_window(cub3d);
	init_image(cub3d);

	pixel_put(&cub3d->img, 100, 100, 0xFF0000);

	mlx_put_image_to_window(
		cub3d->mlx,
		cub3d->win,
		cub3d->img.img,
		0,
		0);

	mlx_hook(cub3d->win, 17, 0, close_window, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, key_press, cub3d);

	mlx_loop(cub3d->mlx);
	return (0);
}
