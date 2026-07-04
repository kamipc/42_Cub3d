/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:48:43 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/02 17:40:13 by sade-ara         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../headers/cub3d.h"

void	free_textures(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->C)
		free(textures->C);
	if (textures->F)
		free(textures->F);
	if (textures->EA)
		free(textures->EA);
	if (textures->WE)
		free(textures->WE);
	if (textures->NO)
		free(textures->NO);
	if (textures->SO)
		free(textures->SO);
	free(textures);
}
