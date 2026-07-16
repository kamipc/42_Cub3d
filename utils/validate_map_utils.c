/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:28:01 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/11 22:49:04 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	floodfill_map(t_cub3d *cub3d, int x, int y, char **map)
{
	if (x < 0 || map[x] == NULL)
		call_error(cub3d, ERROR_MAP_INV);
	if (y < 0 || (y >= (int)ft_strlen(map[x])))
		call_error(cub3d, ERROR_MAP_INV);
	if (map[x][y] == '1')
		return ;
	else
	{
		map[x][y] = '1';
		floodfill_map(cub3d, x + 1, y, map);
		floodfill_map(cub3d, x, y + 1, map);
		floodfill_map(cub3d, x - 1, y, map);
		floodfill_map(cub3d, x, y - 1, map);
	}
}

//since the map can have inaccessible rooms, check if there is a room
//(anywhere where there is a 0 or player character)
//and does floodfill there to check if the room is surrounded by walls
//this checks if the whole map is fully enclosed and not only the room 
//where the player starts
void	verify_walls(t_cub3d *cub3d, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != '1' && map[x][y] != ' ')
				floodfill_map(cub3d, x, y, map);
			y++;
		}
		x++;
	}
}
