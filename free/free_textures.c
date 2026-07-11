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
