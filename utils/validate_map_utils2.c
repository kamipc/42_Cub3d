/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:56:18 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 13:56:54 by cpinho-c         ###   ########.fr       */
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
}

void	verify_map_walls(t_cub3d *cub3d)
{
	copy_map(cub3d);
	//flood_fill_map(cub3d);
}
