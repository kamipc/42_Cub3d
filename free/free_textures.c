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

static void	destroy_texture_images(void *mlx, t_textures *tex)
{
	if (!mlx)
		return ;
	if (tex->img_no.img)
		mlx_destroy_image(mlx, tex->img_no.img);
	if (tex->img_so.img)
		mlx_destroy_image(mlx, tex->img_so.img);
	if (tex->img_ea.img)
		mlx_destroy_image(mlx, tex->img_ea.img);
	if (tex->img_we.img)
		mlx_destroy_image(mlx, tex->img_we.img);
}

void	free_textures(void *mlx, t_textures *textures)
{
	if (!textures)
		return ;
	destroy_texture_images(mlx, textures);
	free(textures->EA);
	free(textures->WE);
	free(textures->NO);
	free(textures->SO);
	free(textures);
}
