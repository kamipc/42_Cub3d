/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:04:40 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/02 17:19:16 by sade-ara         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../headers/cub3d.h"

t_textures	*init_textures(t_cub3d *cub3d)
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	if (!textures)
		call_error(cub3d, strerror(errno));
	ft_memset(textures, 0, sizeof(t_textures));
	return (textures);
}
