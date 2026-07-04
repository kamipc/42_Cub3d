/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:02:54 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 18:40:45 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"



//try to render imgs to verify they are valid
bool	img_is_valid(t_cub3d *cub3d, char *path)
{
	int		h;
	int		w;
	void	*img;

	img = mlx_xpm_file_to_image(cub3d->mlx, path, &w, &h);
	if (!img)
		return (false);
	mlx_destroy_image(cub3d->mlx, img);
	return (true);
}
//send every texture path to try to render
bool	verify_imgs(t_cub3d *cub3d)
{
	// if (!img_is_valid(cub3d, cub3d->textures->C))
	// 	return (false);
	// if (!img_is_valid(cub3d, cub3d->textures->F))
	// 	return (false);
	if (!img_is_valid(cub3d, cub3d->textures->NO))
		return (false);
	if (!img_is_valid(cub3d, cub3d->textures->SO))
		return (false);
	if (!img_is_valid(cub3d, cub3d->textures->EA))
		return (false);
	if (!img_is_valid(cub3d, cub3d->textures->WE))
		return (false);
	return (true);
}

void	validate_textures(t_cub3d *cub3d)
{
	if((!cub3d->textures->NO) || (!cub3d->textures->SO)
		|| (!cub3d->textures->EA) || (!cub3d->textures->WE)
		/* || (cub3d->textures->C) || (!cub3d->textures->F)*/)
		call_error(cub3d,ERROR_MISS_TEXT);
	// if (!verify_imgs(cub3d))
	// 	call_error(cub3d, ERROR_INV_TEXT);
}
