/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:43:15 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 13:30:37 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

t_cub3d	*init_cub3d(void)
{
	t_cub3d	*cub3d;

	cub3d = malloc(sizeof(t_cub3d));
	if (!cub3d)
		call_error(NULL, strerror(errno));
	ft_memset(cub3d, 0, sizeof(t_cub3d));
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		call_error(cub3d, strerror(errno));
	cub3d->player = malloc(sizeof(t_player));
	if (!cub3d->player)
		call_error(cub3d, strerror(errno));
	ft_memset(cub3d->player, 0, sizeof(t_player));
	cub3d->map = init_map(cub3d);
	cub3d->textures = init_textures(cub3d);
	return (cub3d);
}
