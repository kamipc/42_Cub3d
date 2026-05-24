/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:02:54 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/05/22 20:02:54 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

//trim path to remove excess spaces if they exist
int	trim_path(t_cub3d *cub3d, t_textures *textures, char *line, char *type)
{
	char	*temp;

	temp = line;
	if(ft_strnstr(temp, type, ft_strlen(line)) == NULL)
		return (0);
	temp = ft_strtrim((temp + 2, ' '));
	if ((ft_strncmp(type, "NO", 2)) == 0)
		textures->NO = temp;
	else if ((ft_strncmp(type, "S0", 2)) == 0)
		textures->SO = temp;
	else if ((ft_strncmp(type, "S0", 2)) == 0)
		textures->SO = temp;
	else if ((ft_strncmp(type, "EA", 2)) == 0)
		textures->EA = temp;
	else if ((ft_strncmp(type, "WE", 2)) == 0)
		textures->WE = temp;
	else if ((ft_strncmp(type, "F", 1)) == 0)
		textures->F = temp;
	else if ((ft_strncmp(type, "C", 1)) == 0)
		textures->C = temp;
	free(line);
	return (1);
}
//gets the texture path from the file 
void	get_texture_path(t_cub3d *cub3d, t_textures *textures)
{
	int		fd;
	char	*line;

	fd = open(cub3d->map_filename, O_RDONLY);
	if (fd < 0)
		call_error(cub3d, strerror(errno));
	while ((line = get_next_line) != NULL)
	{
		if (trim_path(cub3d, textures, line, "NO") == 1)
			continue ;
		else if (trim_path(cub3d, textures, line, "SO") == 1)
			continue ;
		else if (trim_path(cub3d, textures, line, "EA") == 1)
			continue ;
		else if (trim_path(cub3d, textures, line, "WE") == 1)
			continue ;
		else if (trim_path(cub3d, textures, line, "F") == 1)
			continue ;
		else if (trim_path(cub3d, textures, line, "C") == 1)
			continue ;
		free(line);
	}
	close(fd);
}

//try to render imgs to verify they are valid
bool	img_is_valid(t_cub3d *cub3d, char *path)
{
	int		*h;
	int		*w;
	void	*img;

	img = mlx_png_file_to_image(cub3d->mlx, path, &w, &h);
	if (!img)
	{
		mlx_destroy_display(cub3d->mlx);
		return (false);
	}
	mlx_destroy_image(cub3d->mlx, img);
	mlx_destroy_display(cub3d->mlx);
	return (true);
}
//send every texture path to try to render
bool	verify_imgs(t_cub3d *cub3d)
{
	if (!img_is_valid(cub3d, cub3d->textures->C))
		return (false);
	if (!img_is_valid(cub3d, cub3d->textures->F))
		return (false);
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
	cub3d->textures = init_textures(cub3d);
	get_texture_path(cub3d, cub3d->textures);
	if((!cub3d->textures->C) || (!cub3d->textures->F) || (!cub3d->textures->NO)
		|| (!cub3d->textures->SO) || (!cub3d->textures->EA)
		|| (!cub3d->textures->WE))
		call_error(cub3d,ERROR_MISS_TEXT);
	if (!verify_imgs(cub3d))
		call_error(cub3d, );
}
