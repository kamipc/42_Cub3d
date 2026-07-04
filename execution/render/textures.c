/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:52:09 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/02 17:56:58 by sade-ara         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/cub3d.h"

static void	load_texture(t_cub3d *cub3d, t_img *img, char *path)
{
	printf("mlx  = %p\n", cub3d->mlx);
	printf("path = %s\n", path);
	img->img = mlx_xpm_file_to_image(cub3d->mlx,
			path, &img->width, &img->height);
	if (!img->img)
		call_error(cub3d, "Error loading texture");
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_len, &img->endian);
}

void	load_textures(t_cub3d *cub3d)
{
	load_texture(cub3d, &cub3d->no, cub3d->textures->NO);
	load_texture(cub3d, &cub3d->so, cub3d->textures->SO);
	load_texture(cub3d, &cub3d->ea, cub3d->textures->EA);
	load_texture(cub3d, &cub3d->we, cub3d->textures->WE);
}
