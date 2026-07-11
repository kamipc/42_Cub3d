/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:02:54 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/11 23:20:08 by cpinho-c         ###   ########.fr       */
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
bool	verify_imgs(t_cub3d *cub3d, bool f_rgb, bool c_rgb)
{
	if (!c_rgb)
	{
		if (!img_is_valid(cub3d, cub3d->textures->c))
			return (false);
	}
	if (!f_rgb)
	{
		if (!img_is_valid(cub3d, cub3d->textures->f))
			return (false);
	}
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

bool	is_rgb(t_cub3d *cub3d, char *textures)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (textures[i])
	{
		if (!ft_isdigit(textures[i]) && textures[i] != ',')
			return (false);
		if (textures[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		call_error(cub3d, ERROR_RGB_FORMAT);
	if (!rgb_valid(ft_split(textures, ',')))
		call_error(cub3d, ERROR_RGB_FORMAT);
	return (true);
}

bool	rgb_valid(char **textures)
{
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(textures[0]);
	green = ft_atoi(textures[1]);
	blue = ft_atoi(textures[2]);
	if (red < 0 || red > 255 || green < 0 || green > 255
		|| blue < 0 || blue > 255)
		return (false);
	return (true);
}

void	validate_textures(t_cub3d *cub3d)
{
	bool	is_rgb_f;
	bool	is_rgb_c;

	if ((!cub3d->textures->no) || (!cub3d->textures->so)
		|| (!cub3d->textures->ea) || (!cub3d->textures->we)
		|| (!cub3d->textures->c) || (!cub3d->textures->f))
		call_error(cub3d, ERROR_MISS_TEXT);
	is_rgb_f = is_rgb(cub3d, cub3d->textures->f);
	is_rgb_c = is_rgb(cub3d, cub3d->textures->c);
	if (!verify_imgs(cub3d, is_rgb_f, is_rgb_c))
		call_error(cub3d, ERROR_INV_TEXT);
}
