/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:46:21 by sade-ara          #+#    #+#             */
/*   Updated: 2026/06/27 14:49:21 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	close_win(t_cub3d *cub3d)
{
	printf("Closing window...\n");
	mlx_destroy_image(cub3d->mlx, cub3d->img.img);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	free_cub3d(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}
