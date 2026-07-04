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
	move_player(cub3d);
	cast_rays(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img, 0, 0);
	return (0);
}
 
void	start_game(t_cub3d *cub3d)
{
	init_window(cub3d);
	init_image(cub3d);
	init_player(cub3d);
	ft_memset(&cub3d->keys, 0, sizeof(t_keys));
	mlx_hook(cub3d->win, 17, 0, close_win, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, key_press, cub3d);
	mlx_hook(cub3d->win, 3, 1L << 1, key_release, cub3d);
	mlx_loop_hook(cub3d->mlx, render, cub3d);
	mlx_loop(cub3d->mlx);
}
