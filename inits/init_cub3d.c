/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:43:15 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/05/22 15:43:15 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

t_cub3d	*init_cub3d(void)
{
	t_cub3d	*cub3d;

	cub3d = malloc(sizeof(t_cub3d));
	if (!cub3d)
		call_error(NULL, strerror(errno));
	cub3d->mlx = init_mlx();
	cub3d->map_filename = NULL;
	cub3d->p_start = NULL;
	cub3d->t_textures = NULL;
	return (cub3d);
}
