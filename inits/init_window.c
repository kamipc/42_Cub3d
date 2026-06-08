/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:00:16 by sade-ara          #+#    #+#             */
/*   Updated: 2026/06/08 11:00:16 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	init_window(t_cub3d *cub)
{
	cub->win = mlx_new_window(
		cub->mlx,
		1280,
		720,
		"Cub3D"
	);
	if (!cub->win)
		call_error(cub, "window error");
}