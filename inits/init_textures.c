/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:04:40 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/11 22:50:40 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

t_textures	*init_textures(t_cub3d *cub3d)
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	if (!textures)
		call_error(cub3d, strerror(errno));
	textures->c = NULL;
	textures->f = NULL;
	textures->no = NULL;
	textures->so = NULL;
	textures->ea = NULL;
	textures->we = NULL;
	return (textures);
}
