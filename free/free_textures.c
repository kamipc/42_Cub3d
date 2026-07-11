/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:48:43 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/11 22:50:06 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	free_textures(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->c)
		free(textures->c);
	if (textures->f)
		free(textures->f);
	if (textures->ea)
		free(textures->ea);
	if (textures->we)
		free(textures->we);
	if (textures->no)
		free(textures->no);
	if (textures->so)
		free(textures->so);
	free(textures);
}
