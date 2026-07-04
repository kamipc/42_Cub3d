/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:46:43 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 15:09:19 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	free_map(t_map *map)
{
	if(!map)
		return ;
	if (map->copy_map)
		free_array(map->copy_map);
	if (map->map)
		free_array(map->map);
	free(map);
}
