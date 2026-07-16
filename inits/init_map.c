/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:14:04 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/11 23:14:39 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

t_map	*init_map(t_cub3d *cub3d)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		call_error(cub3d, strerror(errno));
	map->map = NULL;
	map->copy_map = NULL;
	map->player_start_dir = 0;
	map->player_x = 0;
	map->player_y = 0;
	return (map);
}
