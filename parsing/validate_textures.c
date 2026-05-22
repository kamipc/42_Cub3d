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

void	validate_textures(t_cub3d *cub3d)
{
	t_textures	*textures;

	textures = init_textures(cub3d);
	get_texture_path(cub3d, textures);
	
}
