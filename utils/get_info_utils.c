/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:07:13 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 18:42:59 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

//trim path to remove excess spaces if they exist and the \n at the end 
bool	trim_path(t_textures *textures, char *line, char *type)
{
	char	*temp;

	temp = line;
	if(ft_strnstr(temp, type, ft_strlen(line)) == NULL)
		return (false);
	temp = temp + 2;
	temp = ft_strtrim(temp, " ");
	free(line);
	line = temp;
	temp = ft_strtrim(line, "\n");
	if ((ft_strncmp(type, "NO", 2)) == 0)
		textures->NO = temp;
	else if ((ft_strncmp(type, "SO", 2)) == 0)
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
	return (true);
}

bool	is_junk(char *line)
{
	int	i;

	i = 0;
	if (is_map_start(line))
		return (false);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}
bool	save_textures(t_cub3d *cub3d, char *line)
{
	if (trim_path(cub3d->textures, line, "NO"))
		return (true);
	else if (trim_path(cub3d->textures, line, "SO"))
		return (true);
	else if (trim_path(cub3d->textures, line, "EA"))
		return (true);
	else if (trim_path(cub3d->textures, line, "WE"))
		return (true);
	else if (trim_path(cub3d->textures, line, "F"))
		return (true);
	else if (trim_path(cub3d->textures, line, "C"))
		return (true);
	else
		return (false);
}

bool	is_map_start(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	save_map(t_cub3d *cub3d, char *line, int *i)
{
	char	*new_map_line;
	char	**new_map;

	new_map_line = ft_strdup(line);
	new_map = ft_realloc(cub3d->map->map, *i * sizeof(char *), (*i + 1) * sizeof(char *));
	if ((!new_map) || (!new_map_line))
	{
		free(line);
		call_error(cub3d, strerror(errno));
	}
	cub3d->map->map = new_map;
	cub3d->map->map[*i] = new_map_line;
	(*i)++;
	cub3d->map->map[*i] = NULL;
}