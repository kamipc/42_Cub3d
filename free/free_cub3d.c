/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:43:23 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 14:46:28 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	free_cub3d(t_cub3d *cub3d)
{
	if (!cub3d)
		return ;
	if (cub3d->mlx)
	{
		mlx_destroy_display(cub3d->mlx);
		free(cub3d->mlx);
	}
	if (cub3d->map_filename)
		free(cub3d->map_filename);
	if (cub3d->map)
		free_map(cub3d->map);
	if (cub3d->textures)
		free_textures(cub3d->textures);
	free(cub3d);
}
