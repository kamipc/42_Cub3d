/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:48:43 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 15:09:26 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
