/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 17:28:49 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/04 17:28:49 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	load_one_texture(t_cub3d *cub3d, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(cub3d->mlx, path,
			&img->width, &img->height);
	if (!img->img)
		call_error(cub3d, ERROR_INV_TEXT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
}

void	load_texture_images(t_cub3d *cub3d)
{
	load_one_texture(cub3d, cub3d->textures->NO, &cub3d->textures->img_no);
	load_one_texture(cub3d, cub3d->textures->SO, &cub3d->textures->img_so);
	load_one_texture(cub3d, cub3d->textures->EA, &cub3d->textures->img_ea);
	load_one_texture(cub3d, cub3d->textures->WE, &cub3d->textures->img_we);
}
