/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:04:40 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/05/22 20:04:40 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

t_textures	*init_textures(t_cub3d *cub3d)
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	if (!textures)
		call_error(cub3d, strerror(errno));
	textures->C = NULL;
	textures->F = NULL;
	textures->NO = NULL;
	textures->SO = NULL;
	textures->EA = NULL;
	textures->WE = NULL;
	return (textures);
}
