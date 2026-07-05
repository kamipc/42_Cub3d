/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:48:43 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/05 17:43:00 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free(textures->ea);
	free(textures->we);
	free(textures->no);
	free(textures->so);
	free(textures);
}
