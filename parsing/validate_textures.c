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

bool	verify_imgs(t_cub3d *cub3d)
{
	if (!img_is_valid(cub3d, cub3d->textures->no))
		return (false);
	if (!img_is_valid(cub3d, cub3d->textures->so))
		return (false);
	if (!img_is_valid(cub3d, cub3d->textures->ea))
		return (false);
	if (!img_is_valid(cub3d, cub3d->textures->we))
		return (false);
	return (true);
}

void	validate_textures(t_cub3d *cub3d)
{
	if ((!cub3d->textures->no) || (!cub3d->textures->so)
		|| (!cub3d->textures->ea) || (!cub3d->textures->we))
		call_error(cub3d, ERROR_MISS_TEXT);
	if (!verify_imgs(cub3d))
		call_error(cub3d, ERROR_INV_TEXT);
}
