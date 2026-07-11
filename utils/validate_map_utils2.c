/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:56:18 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/05 11:59:27 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	copy_map(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map->map[i])
		i++;
	cub3d->map->copy_map = (char **)malloc((i + 1) * sizeof(char *));
	if (!cub3d->map->copy_map)
		call_error(cub3d, strerror(errno));
	i = 0;
	while (cub3d->map->map[i])
	{
		cub3d->map->copy_map[i] = ft_strdup(cub3d->map->map[i]);
		i++;
	}
	cub3d->map->copy_map[i] = NULL;
}

static bool	flood_fill(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->height)
		return (false);
	if (x < 0 || (size_t)x >= ft_strlen(map->copy_map[y]))
		return (false);
	if (map->copy_map[y][x] == '1' || map->copy_map[y][x] == 'V')
		return (true);
	if (map->copy_map[y][x] == ' ')
		return (false);
	map->copy_map[y][x] = 'V';
	if (!flood_fill(map, x + 1, y) || !flood_fill(map, x - 1, y))
		return (false);
	return (flood_fill(map, x, y + 1) && flood_fill(map, x, y - 1));
}

void	verify_map_walls(t_cub3d *cub3d)
{
	t_map	*map;
	bool	closed;

	map = cub3d->map;
	copy_map(cub3d);
	closed = flood_fill(map, map->player_x, map->player_y);
	free_array(map->copy_map);
	map->copy_map = NULL;
	if (!closed)
		call_error(cub3d, ERROR_MAP_CHAR);
}
