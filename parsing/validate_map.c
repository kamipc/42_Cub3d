/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:26:49 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/05 11:59:46 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	pad_row(t_cub3d *cub3d, t_map *map, int i)
{
	char	*padded;
	int		len;
	int		j;

	len = ft_strlen(map->map[i]);
	if (len == map->width)
		return ;
	padded = malloc(map->width + 1);
	if (!padded)
		call_error(cub3d, strerror(errno));
	j = 0;
	while (j < len)
	{
		padded[j] = map->map[i][j];
		j++;
	}
	while (j < map->width)
		padded[j++] = ' ';
	padded[j] = '\0';
	free(map->map[i]);
	map->map[i] = padded;
}

static void	pad_map(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map->map[i])
	{
		pad_row(cub3d, cub3d->map, i);
		i++;
	}
}

static void	set_map_dimensions(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	map->width = 0;
	while (map->map[i])
	{
		len = ft_strlen(map->map[i]);
		if (len > map->width)
			map->width = len;
		i++;
	}
	map->height = i;
}

void	validate_map(t_cub3d *cub3d)
{
	set_map_dimensions(cub3d->map);
	pad_map(cub3d);
	verify_map_characters(cub3d);
	verify_map_walls(cub3d);
}
