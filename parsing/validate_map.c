/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:26:49 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/16 21:03:33 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

bool	is_player_start(char c, int *playernum)
{
	if ((c == 'N') || (c == 'S') || (c == 'W') || (c == 'E'))
	{
		(*playernum)++;
		return (true);
	}
	return (false);
}

//verify that the map has at least 1 player and no more than 1 
void	verify_map_player(t_cub3d *cub3d)
{
	int		i;
	int		j;
	int		playernum;

	i = 0;
	playernum = 0;
	while (cub3d->map->map[i])
	{
		j = 0;
		while (cub3d->map->map[i][j])
		{
			if (is_player_start(cub3d->map->map[i][j], &playernum))
			{
				if (playernum > 1)
					call_error(cub3d, ERROR_MAP_PLAYER);
				cub3d->map->player_start_dir = cub3d->map->map[i][j];
				cub3d->map->player_x = j;
				cub3d->map->player_y = i;
			}
			j++;
		}
		i++;
	}
	if (playernum == 0)
		call_error(cub3d, ERROR_MAP_PLAYER);
}

//makes a copy of the map to be used later for floodfill
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

void	validate_map(t_cub3d *cub3d)
{
	verify_map_player(cub3d);
	copy_map(cub3d);
	verify_walls(cub3d, cub3d->map->copy_map);
}
