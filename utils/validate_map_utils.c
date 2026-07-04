/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:28:01 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 13:54:23 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

bool	not_valid_character(char c)
{
	if ((c != '0') && (c != '1') && (c != 'N') && (c != 'S') && (c != 'W')
		&& (c != 'E') && (c != ' '))
		return (true);
	return (false);
}

bool	is_player_start(char c, int *playernum)
{
	if ((c != 'N') || (c != 'S') || (c != 'W') || (c != 'E'))
	{
		(*playernum)++;
		return (true);
	}
	return (false);
}

void	verify_map_characters(t_cub3d *cub3d)
{
	int		i;
	int		j;
	int	playernum;

	i = 0;
	playernum = 0;
	while (cub3d->map->map[i])
	{
		j = 0;
		while (cub3d->map->map[i][j])
		{
			if (not_valid_character(cub3d->map->map[i][j]))
				call_error(cub3d, ERROR_MAP_CHAR);
			if (is_player_start(cub3d->map->map[i][j], &playernum))
				{
					if (playernum > 1)
						call_error(cub3d, ERROR_MAP_PLAYER);
					cub3d->map->player_start_dir = cub3d->map->map[i][j];
					cub3d->map->player_x = i;
					cub3d->map->player_y = j;
				}
			j++;
		}
		i++;
	}
}
