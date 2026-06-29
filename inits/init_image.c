/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:08:46 by sade-ara          #+#    #+#             */
/*   Updated: 2026/06/29 14:08:46 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	init_image(t_cub3d *cub3d)
{
	cub3d->img.img = mlx_new_image(
		cub3d->mlx,
		WIN_WIDTH,
		WIN_HEIGHT);
	cub3d->img.addr = mlx_get_data_addr(
		cub3d->img.img,
		&cub3d->img.bpp,
		&cub3d->img.line_len,
		&cub3d->img.endian);
}
