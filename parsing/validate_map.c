/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:26:49 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/09 21:50:30 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	validate_map(t_cub3d *cub3d)
{
	cub3d->map = init_map(cub3d);
	verify_map_characters(cub3d);
	verify_map_walls(cub3d);
}
