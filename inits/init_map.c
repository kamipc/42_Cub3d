/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:14:04 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/05/24 16:14:04 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

t_map	init_map(t_cub3d *cub3d)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		call_error(cub3d, strerror(errno));
	map->map = (char **)malloc(1 * sizeof(char *));
	if (!map->map)
		call_error(cub3d, strerror(errno));
	map->map[0] = NULL;
	map->copy_map = NULL;
	map->player_start = NULL;
	return (map);
}
